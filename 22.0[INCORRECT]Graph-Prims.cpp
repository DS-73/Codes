#include <iostream>
#include <vector>
#include <queue>

#define ppair pair<int, pair<int, int>>

using namespace std;

int find(int u, vector<int> &disjoint_set){
    if(disjoint_set[u] < 0){
        return u;
    }
    return find(disjoint_set[u], disjoint_set);
}

void print_heap(priority_queue<ppair, vector<ppair>, greater<ppair>> &min_heap){
    priority_queue<ppair, vector<ppair>, greater<ppair>> temp_heap = min_heap;
    while(!temp_heap.empty()){
        cout << temp_heap.top().first << " : " << temp_heap.top().second.first << " " << temp_heap.top().second.second << endl; 
        temp_heap.pop();
    }cout << endl;
}

vector<ppair> prims_algorithm(vector<vector<int>> &graph, vector<int> &disjoint_set){
    priority_queue<ppair, vector<ppair>, greater<ppair>> min_heap;
    for(int i = 0; i < graph[0].size(); ++i){
        if(graph[0][i] != 0){
            min_heap.push(make_pair(graph[0][i], make_pair(0, i)));
        }
    }

    vector<ppair> minimum_spannning_tree;
    while(!min_heap.empty()){
        print_heap(min_heap);
        ppair p = min_heap.top();       min_heap.pop();
        int pu = find(p.second.first, disjoint_set), pv = find(p.second.second, disjoint_set);
        if(pu != pv){
            if(pu < pv){
                disjoint_set[pu] = disjoint_set[pu] + disjoint_set[pv];
                disjoint_set[pv] = pu;
            } else{
                disjoint_set[pv] = disjoint_set[pu] + disjoint_set[pv];
                disjoint_set[pu] = pv;    
            }

            for(int i = 0; i < graph[p.second.second].size(); ++i){
                if(graph[p.second.second][i] != 0){
                    min_heap.push(make_pair(graph[p.second.second][i], make_pair(p.second.second, i)));
                }
            }
            minimum_spannning_tree.push_back(p);
            cout << "Edge added : " << p.first << " : " << p.second.first << " " << p.second.second << endl;
        } else{
            cout << "> Cycle detected : " << p.first << " : " << p.second.first << " " << p.second.second << endl;
        }
    }
    return minimum_spannning_tree;
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int v;      cin >> v;
    vector<vector<int>> graph(v, vector<int>(v, 0));
    for(int i = 0; i < v; ++i){
        for(int j = 0; j < v; ++j){
            cin >> graph[i][j];
        }
    }

    vector<int> disjoint_set(v, -1);
    vector<ppair> min_spanning_tree = prims_algorithm(graph, disjoint_set);

    cout << "---- Graph ----" << endl;
    for(auto x: min_spanning_tree){
        cout << x.first << " : " << x.second.first << " " << x.second.second << endl;
    }

    return 0;
}

/*

    7
    0 0 7 5 0 0 0
    0 0 8 5 0 0 0
    7 8 0 9 7 0 0
    5 0 9 0 15 6 0
    0 5 7 15 0 8 9
    0 0 0 6 8 0 11
    0 0 0 0 9 11 0



*/

