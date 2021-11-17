#include <iostream>
#include <cmath>

using namespace std;

void solve(int* array, int n, int key){
    int jump = 1, last_index = 0;
    while(array[min(jump, n) - 1] < key){
        last_index = jump;
        jump  *= 2;

        if(jump >= n){
            break;
        }
    }

    jump = min(jump, n-1);
    while(last_index <= jump){
        if(array[last_index] == key){
            cout << "Element Found at index " << last_index << endl;
            return;
        }
        ++last_index;
    }
    cout << "Element Not found" << endl;
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
        int key;        cin >> key;
        solve(array, n, key);

    }

    return 0;
}
