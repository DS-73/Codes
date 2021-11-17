#include <iostream>
#include <vector>
#include <queue>

#define ppair pair<int, pair<int, int>>

using namespace std;

void print_heap(priority_queue<ppair, vector<ppair>, greater<ppair>> &min_heap){    
    priority_queue<ppair, vector<ppair>, greater<ppair>> temp_heap = min_heap;
    while(!temp_heap.empty()){
        cout << temp_heap.top().first << " : " << temp_heap.top().second.first << " " << temp_heap.top().second.second << endl;
        temp_heap.pop();
    }
}

int find(int u, vector<int> &disjoint_set){
    if(disjoint_set[u] < 0){
        return u;
    }
    return find(disjoint_set[u], disjoint_set);
}

vector<ppair> kruskal_algorithm(vector<ppair> &graph, vector<int> &disjoint_set){  
    priority_queue<ppair, vector<ppair>, greater<ppair>> min_heap(graph.begin(), graph.end());
    vector<ppair> minimum_spanning_tree;

    while(!min_heap.empty()){
        ppair p = min_heap.top();       min_heap.pop();
        int pu = find(p.second.first, disjoint_set), pv = find(p.second.second, disjoint_set);

        if(pu != pv){
            if(disjoint_set[pu] < disjoint_set[pv]){
                disjoint_set[pu] = disjoint_set[pu] + disjoint_set[pv];
                disjoint_set[pv] = pu;
            } else{
                disjoint_set[pv] = disjoint_set[pu] + disjoint_set[pv];
                disjoint_set[pu] = pv;
            }
            minimum_spanning_tree.push_back(make_pair(p.first, make_pair(p.second.first, p.second.second)));
            cout << "Edge added : " << p.first << " : " << p.second.first << " " << p.second.second << endl;
        } else{
            cout << "> Cycle Detected : " << p.first << " : " << p.second.first << " " << p.second.second << endl;
        }
    }

    return minimum_spanning_tree;
}

int main(){
    #ifndef ONLINE_JUGDE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int v, e;       cin >> v >> e;
    vector<ppair> graph;
    vector<int> disjoint_set(v, -1);
    
    for(int i = 0; i < e; ++i){
        int w, s, d;        cin >> w >> s >> d;
        graph.push_back(make_pair(w, make_pair(s, d)));
    }
    vector<ppair> min_spanning_tree = kruskal_algorithm(graph, disjoint_set);
    cout << endl;
    cout << "---- Graph ----" << endl;
    for(auto x: min_spanning_tree){
        cout << x.first << " : " << x.second.first << " " << x.second.second << endl;
    }

 
    return 0;
}


/*

    1 7 6
    2 8 2
    2 6 5
    4 0 1
    4 2 5
    6 8 6
    7 2 3
    7 7 8
    8 0 7
    8 1 2
    9 3 4
    10 5 4
    11 1 7
    14 3 5


    7 22
    7 0 2
    5 0 3
    8 1 2
    5 1 3
    7 2 0
    8 2 1
    9 2 3
    7 2 4
    5 3 0
    9 3 2
    15 3 4
    6 3 5
    5 4 1
    7 4 2
    15 4 3
    8 4 5
    9 4 6
    6 5 3
    8 5 4
    11 5 6
    9 6 4
    11 6 5


*/