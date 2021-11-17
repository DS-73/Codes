#include <iostream>

using namespace std;

void heapify(int *array, int n, int i){
    int left = 2*i + 1, right = 2*i + 2;
    int maximum = i;

    if(left < n && array[left] > array[maximum]){
        maximum = left;
    }
    if(right < n && array[right] > array[maximum]){
        maximum = right;
    }

    if(maximum != i){
        swap(array[i], array[maximum]);
        heapify(array, n, maximum);
    }
    
}

void buildheap(int *array, int n){
    for(int i = n/2; i > -1; --i){
        heapify(array, n, i);
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

        buildheap(array, n);

        cout << "Maximum Heap : ";
        for(int i = 0; i < n; ++i){
            cout << array[i] << " ";
        }cout << endl;
    }

    return 0;
}
