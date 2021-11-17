#include <iostream>

using namespace std;

void heapify(int *array, int i, int n){
    int left = 2*i + 1, right = 2*i + 2;
    int minimum = i;
    if(left < n && array[left] < array[minimum]){
        minimum = left;
    }
    if(right < n && array[right] < array[minimum]){
        minimum = right;
    }

    if(minimum != i){
        swap(array[i], array[minimum]);
        heapify(array, minimum, n);
    }
}

void buildheap(int *array, int n){
    for(int i = n/2; i > -1; --i){
        heapify(array, i, n);
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

        buildheap(array, n);
        cout << "Heap Values : ";
        for(int i = 0; i < n; ++i){
            cout << array[i] << " ";
        }cout << endl;
    }

    return 0;
}
