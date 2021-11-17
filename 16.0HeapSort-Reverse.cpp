#include <iostream>

using namespace std;

class min_heap{
    private: 
        int *heap, heap_size, capacity;
        int get_parent(int i){
            return (i - 1)/2;
        }
        int get_left_child(int i){
            return 2*i + 1;
        }
        int get_right_child(int i){
            return 2*i + 2;
        }

    public:
        min_heap(int capacity){
            this->capacity = capacity;
            heap = new int[capacity];

            heap_size = 0;
        }
        void heapify(int index){
            int minimum = index, left_child = get_left_child(index), right_child = get_right_child(index);
            if(left_child < heap_size && heap[minimum] > heap[left_child]){
                minimum = left_child;
            }
            if(right_child < heap_size && heap[minimum] > heap[right_child]){
                minimum = right_child;
            }

            if(minimum != index){
                swap(heap[index], heap[minimum]);
                heapify(minimum);
            }
        }
        void insert(int val){
            if(heap_size == capacity){
                cout << "Heap Overflow" << endl;
                return;
            }

            int index = heap_size;      ++heap_size;
            heap[index] = val;

            while(index != 0 && heap[get_parent(index)] > heap[index]){
                swap(heap[get_parent(index)], heap[index]);
                index = get_parent(index);
            }
        }
        void sort(){
            while(heap_size){
                swap(heap[heap_size - 1], heap[0]);
                --heap_size;

                heapify(0);
            }
        }
        
        int* get_array(){
            return heap;
        }

};

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif 

    int t;      cin >> t;

    while(t--){
        int n;      cin >> n;
        min_heap *obj = new min_heap(n);
        
        for(int i = 0; i < n; ++i){
            int val;        cin >> val;
            obj->insert(val);
        }

        obj->sort();

        int *sorted_array = obj->get_array();
        cout << "Reverse Sorted Array : ";
        for(int i = 0; i < n; ++i){
            cout << sorted_array[i] << " ";
        }cout << endl;

    }

    return 0;
}
