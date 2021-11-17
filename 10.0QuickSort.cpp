#include <iostream>
#include <cmath>

using namespace std;

int partition(int *array, int low, int high){
    int pivot = low-1;
    for(int i = low; i < high; ++i){
        if(array[i] < array[high]){
            ++pivot;
            swap(array[i], array[pivot]);
        }
    }
    ++pivot;     
    swap(array[high], array[pivot]);   
    return pivot;
}

void quick_sort(int* array, int low, int high){
    if(low >= high){
        return;
    }
    int pivot = partition(array, low, high);

    quick_sort(array, low, pivot - 1);
    quick_sort(array, pivot + 1, high);
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
        quick_sort(array, 0, n-1);

        cout << "Sorted Array : ";
        for(int i = 0; i < n; ++i){
            cout << array[i] << " ";
        }cout << endl;
        delete[] array;
    }

    return 0;
}
