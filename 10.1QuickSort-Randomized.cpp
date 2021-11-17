#include <iostream>
#include <time.h>

using namespace std;

int partition(int *array, int low, int high){
    srand(time(0));
    int random_index = low + rand() % (high - low);
    swap(array[high], array[random_index]);

    int pivot = low-1;
    for(int i = low; i < high; ++i){
        if(array[i] < array[high]){
            ++pivot;
            swap(array[pivot], array[i]);
        }
    }
    ++pivot;
    swap(array[pivot], array[high]);
    return pivot;
}

void quick_sort(int *array, int low, int high){
    if(low < high){
        int pivot = partition(array, low, high);

        quick_sort(array, low, pivot-1);
        quick_sort(array, pivot+1, high);
    }
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
        } cout << endl;
    }

    return 0;
}
