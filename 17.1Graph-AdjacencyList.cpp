#include <iostream>
#include <vector>

using namespace std;

void print(vector<vector<pair<int, int>>> &graph){
    for(int i = 0; i < graph.size(); ++i){
        cout << "--> Source : " << i << endl;
        for(int j = 0; j < graph[i].size(); ++j){
            cout << "> Destination : " << graph[i][j].first << " Weight : " << graph[i][j].second << endl;
        }cout << endl;
    }cout << endl;
}

void delete_element(vector<vector<pair<int, int>>> &graph, int source, int destination){
    for(int i = 0; i < graph[source].size(); ++i){
        if(graph[source][i].first == destination){
            graph[source].erase(graph[source].begin() + i);
            return;
        }
    }
    cout << " -- No Edge Detected " << endl;
}

int main(){
    #ifndef ONLINE_JDUGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int t;      cin >> t;

    while(t--){
        int v, e;      cin >> v >> e;
        vector<vector<pair<int, int>>> graph(v, vector<pair<int, int>>());
        for(int i = 0; i < e; ++i){
            int s, d, w;       cin >> s >> d >> w;
            graph[s].push_back(make_pair(d, w));
        }
        print(graph);
        delete_element(graph, 0, 2);
        print(graph);
        
    }

    return 0;
}

