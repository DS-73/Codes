#include <iostream>

using namespace std;

class max_heap{
    private: 
        int *heap, heap_size, capacity;
        int get_parent(int i){
            return (i-1)/2;
        }
        int get_left_child(int i){
            return 2*i + 1;
        }
        int get_right_child(int i){
            return 2*i + 2;
        }

    public:
        max_heap(int capacity){
            this->capacity = capacity;
            heap = new int[capacity];

            heap_size = 0;
        }
        void heapify(int index){
            int maximum = index, left_child = get_left_child(index), right_child = get_right_child(index);
            if(left_child < heap_size && heap[maximum] < heap[left_child]){
                maximum = left_child;
            }
            if(right_child < heap_size && heap[maximum] < heap[right_child]){
                maximum = right_child;
            }

            if(maximum != index){
                swap(heap[maximum], heap[index]);
                heapify(maximum);
            }
            
        }
        void insert(int val){
            if(heap_size == capacity){
                cout << "Heap Overflow" << endl;
                return;
            }

            int index = heap_size;      ++heap_size;
            heap[index] = val;

            while(index != 0 && heap[index] > heap[get_parent(index)]){
                swap(heap[index], heap[get_parent(index)]);
                index = get_parent(index);
            }
        }
        void sort(){
            while(heap_size){
                --heap_size;
                swap(heap[heap_size], heap[0]);

                heapify(0);
            }
        }
        void print(){
            cout << "Maximum Heap : ";
            for(int i = 0; i < heap_size; ++i){
                cout << heap[i] << " ";
            }cout << endl;
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
        max_heap *obj = new max_heap(n);

        for(int i = 0; i < n; ++i){
            int val;        cin >> val;
            obj->insert(val);
        }
        
        obj->sort();
        int *array = obj->get_array();
        cout << "Sorted Array : ";
        for(int i = 0; i < n; ++i){
            cout << array[i] << " ";
        } cout << endl;

    }

    return 0;
}
