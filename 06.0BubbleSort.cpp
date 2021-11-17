#include <iostream>
#include <cmath>

using namespace std;

void solve(int* array, int n){
    for(int i = 0; i < n - 1; ++i){
        for(int j = 0; j < n - i - 1; ++j){
            if(array[j] > array[j + 1]){
                swap(array[j], array[j + 1]);
            }
        }
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
