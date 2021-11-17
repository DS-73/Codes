#include <iostream>

using namespace std;

void heapify(int *heap, int n, int index){
    int maximum = index, left_child = 2*index + 1, right_child = 2*index + 2;
    if(left_child < n && heap[index] < heap[left_child]){
        maximum = left_child;
    }
    if(right_child < n && heap[index] < heap[right_child]){
        maximum = right_child;
    }

    if(maximum != index){
        swap(heap[maximum], heap[index]);
        heapify(heap, n, maximum);
    }

}

void heap_sort(int *heap, int n){
    for(int i = n/2; i > -1; --i){
        heapify(heap, n, i);
    }

    for(int i = n-1; i > 0; --i){
        swap(heap[i], heap[0]);
        heapify(heap, i, 0);
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
        int *heap = new int[n];
        for(int i = 0; i < n; ++i){
            cin >> heap[i];
        }

        heap_sort(heap, n);

        cout << "Sorted Array : ";
        for(int i = 0; i < n; ++i){
            cout << heap[i] << " ";
        }cout << endl;
    }

    return 0;
}
