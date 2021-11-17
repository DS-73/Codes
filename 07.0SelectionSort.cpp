#include <iostream>
#include <cmath>

using namespace std;

void solve(int* array, int n){
    for(int i = 0; i < n - 1; ++i){
        int min_index = i;
        for(int j = i + 1; j < n; ++j){
            if(array[min_index] > array[j]){
                min_index = j;
            }
        }
        swap(array[min_index], array[i]);
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
