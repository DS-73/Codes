#include <iostream>
#include <cmath>

using namespace std;

void solve(int* array, int n){
    for(int i = 1; i < n; ++i){
        int j = i - 1, key = array[i];
        while(j > -1 && array[j] > key){
            array[j + 1] = array[j];
            --j;
        }
        array[j + 1] = key;
    }

    cout << "Sorted Array : " ;
    for(int i = 0; i < n; ++i){
        cout << array[i] << ", ";
    }cout << endl;
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
        solve(array, n);
    }

    return 0;
}
