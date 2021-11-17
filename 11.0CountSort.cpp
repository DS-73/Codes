#include <iostream>

using namespace std;

void count_sort(int *array, int n){
    int *count_array = new int[10000];
    for(int i = 0; i < 10000; ++i){
        count_array[i] = 0;
    }
    for(int i = 0; i < n; ++i){
        ++count_array[array[i]];
    }
    for(int i = 1; i < 10000; ++i){
        count_array[i] = count_array[i] + count_array[i - 1];
    }

    int *res_array = new int[n];
    for(int i = 0; i < n; ++i){
        res_array[count_array[array[i]] - 1] = array[i];
        --count_array[array[i]];
    }
    
    for(int i = 0; i < n; ++i){
        array[i] = res_array[i];
    }
    
    
}

int main(){
    #ifndef ONLINE_JDUGE
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

        count_sort(array, n);

        cout << "Sorted : ";
        for(int i = 0; i < n; ++i){
            cout << array[i] << " ";
        }cout << endl;
    }


    return 0;
}
