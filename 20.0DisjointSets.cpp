#include <iostream>
#include <vector>

using namespace std;

int find(int u, vector<int> &disjoint_set){
    if(disjoint_set[u] < 0){
        return u;
    }
    return find(disjoint_set[u], disjoint_set);
}

bool unionby_weight(int u, int v, vector<int> &disjoint_set){
    int pu = find(u, disjoint_set), pv = find(v, disjoint_set);
    bool flag = pu != pv;

    if(flag){
        if(disjoint_set[pu] <= disjoint_set[pv]){
            disjoint_set[pu] = disjoint_set[pv] + disjoint_set[pu];
            disjoint_set[pv] = pu;  
        }
        else{   
            disjoint_set[pv] = disjoint_set[pv] + disjoint_set[pu];
            disjoint_set[pu] = pv; 
        }
    }
    return flag;
}

void print(vector<int> &disjoint_set){
    cout << "Disjoint Set : ";
    for(int i = 0; i < disjoint_set.size(); ++i){
        cout << disjoint_set[i] << " ";
    }cout << endl;
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int e, v;      cin >> e >> v;
    vector<int> disjoint_set(v, -1);

    for(int i = 0; i < e; ++i){
        int u, v;       cin >> u >> v;
        if(!unionby_weight(u, v, disjoint_set)){
            cout << "> Cycle detected " << endl;
        } else{
            print(disjoint_set);
        }
    }


    return 0;
}
