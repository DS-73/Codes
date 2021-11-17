#include <iostream>
#include <vector>

using namespace std;

void print(vector<vector<int>> &graph){
    cout << "---- Graph ----" << endl;
    for(int i = 0; i < graph.size(); ++i){
        for(int j = 0; j < graph[i].size(); ++j){
            cout << graph[i][j] << " ";
        }cout << endl;
    }cout << endl;
}

void delete_element(vector<vector<int>> &graph, int source, int destination){
    if(graph[source][destination] == 0){
        cout << "--- No edge detected" << endl;
    } else{
        graph[source][destination] = 0;
    }
}

int main(){
    #ifndef ONLINE_JDUGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int t;      cin >> t;

    while(t--){
        int v, e;      cin >> v >> e;
        vector<vector<int>> graph(v, vector<int>(v, 0));
        for(int i = 0; i < e; ++i){
            int s, d, w;       cin >> s >> d >> w;
            graph[s][d] = w;
        }
        print(graph);
        delete_element(graph, 0, 2);
        print(graph);

    }

    return 0;
}
