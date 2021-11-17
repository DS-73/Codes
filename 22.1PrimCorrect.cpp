#include <iostream>
#include <vector>
#include <queue>
#include <climits>

#define ppair pair<int, pair<int, int>>

using namespace std;

void print_heap(priority_queue<ppair, vector<ppair>, greater<ppair>> &min_heap){
    priority_queue<ppair, vector<ppair>, greater<ppair>> temp_heap = min_heap;
    while(!temp_heap.empty()){
        cout << temp_heap.top().first << " : " << temp_heap.top().second.first << " " << temp_heap.top().second.second << endl; 
        temp_heap.pop();
    }cout << endl;
}

void print_output(vector<int> &parent, vector<int> &weights){
    int cost = 0;
    for(int i = 1; i < parent.size(); ++i){
        cout << parent[i] << " " << i << " : " << weights[i] << endl;
        if(weights[i] != INT_MAX)
            cost = cost + weights[i];
    }
    cout << endl << "Cost : " << cost << endl;
    cout << endl;
}

void prims_algorithm(vector<vector<int>> &graph){
    priority_queue<ppair, vector<ppair>, greater<ppair>> min_heap;
    min_heap.push(make_pair(0, make_pair(0, 0)));

    vector<int> parent(graph.size(), -1), weights(graph.size(), INT_MAX);
    vector<bool> visited(graph.size(), false);      weights[0] = 0;

    while(!min_heap.empty()){
        int i = min_heap.top().second.first;
        min_heap.pop();
        if(visited[i] == false){
            for(int j = 0; j < graph.size(); ++j){
                if(!visited[j] && graph[i][j] != 0 && graph[i][j] < weights[j]){
                    weights[j] = graph[i][j];       parent[j] = i;
                    min_heap.push(make_pair(weights[j], make_pair(j, i)));
                }
            }   visited[i] = true;
        }
    }
    print_output(parent, weights);
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
    
    prims_algorithm(graph);

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

