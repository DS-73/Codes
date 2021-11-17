#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

void bfs(vector<vector<pair<int, int>>> &graph){
    vector<bool> visited(graph.size(), false);
    queue<int> q;       q.push(0);
    visited[0] = true;

    cout << " --- Breadth First Traversal --- " << endl;
    while(!q.empty()){
        cout << "Node " << q.front() << " visited" << endl;
        for(int i = 0; i < graph[q.front()].size(); ++i){
            if(!visited[graph[q.front()][i].first]){
                q.push(graph[q.front()][i].first);
                visited[graph[q.front()][i].first] = true;
            }
            cout << " > Destination : " << graph[q.front()][i].first << " Weight : " << graph[q.front()][i].second << endl;
            
        }
        q.pop();
    }
}

void dfs(vector<vector<pair<int, int>>> &graph){
    vector<bool> visited(graph.size(), false);
    stack<int> st;      st.push(0);
    visited[0] = true;

    cout << " --- Depth First Traversal --- " << endl;
    while(!st.empty()){
        cout << "Node " << st.top() << " visited" << endl;
        int top = st.top();         st.pop();

        for(int i = 0; i < graph[top].size(); ++i){
            if(!visited[graph[top][i].first]){
                st.push(graph[top][i].first);
                visited[graph[top][i].first] = true;
            }
            cout << " > Destination : " << graph[top][i].first << " Weight : " << graph[top][i].second << endl;
        }
        
    }

}

void print(vector<vector<pair<int, int>>> &graph){
    for(auto x: graph){
        for(auto y: x){
            cout << y.first << " : " << y.second << endl;
        }cout << endl;
    }
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int v, e;           cin >> v >> e;
    
    vector<vector<pair<int, int>>> graph(v, vector<pair<int, int>>());
    for(int i = 0; i < e; ++i){
        int s, d, w;        cin >> s >> d >> w;
        graph[s].push_back(make_pair(d, w));
    }
    // print(graph);
    bfs(graph);     cout << endl << endl;
    dfs(graph);

    return 0;
}

/*

    4 6
    0 1 2
    0 2 7
    1 2 11 
    2 0 16
    2 3 17
    3 3 29

*/