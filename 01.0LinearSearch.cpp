#include <iostream>

using namespace std;

void solve(int *array, int n, int k){
    int counter = 0;
    for(int i = 0; i < n; ++i){
        ++counter;
        if(array[i] == k){
            cout << "Key matched at index " << i << endl;
            cout << "> Number of comparision : " << counter << endl;
            cout << endl;
            return;
        }
    }
    cout << "Key not matched " << endl;
    cout << "> Number of comparision : " << counter << endl;
    cout << endl;
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int t;      cin >> t;
    while(t--){
        int n;      cin >> n;
        int *array = new int[n];
        for(int i = 0; i < n; ++i){
            cin >> array[i];
        }

        int k;      cin >> k;
        solve(array, n, k);
    }

    return 0;
}
