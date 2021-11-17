#include <iostream>

using namespace std;

class max_heap{
    private:
        int *heap, capacity, heap_size;
        int get_parent(int i){
            return ((i-1)/2);
        }
        int get_left_child(int i){
            return (2*i + 1);
        }
        int get_right_child(int i){
            return (2*i + 2);
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
                cout << "Heap is full" << endl;
                return;
            }

            int index = heap_size, parent = get_parent(index);
            ++heap_size;
            heap[index] = val;

            while(index != 0 && heap[parent] < heap[index]){
                swap(heap[index], heap[parent]);
                index = parent;
                parent = get_parent(index);
            }
        }
        void print(){
            if(heap_size == 0){
                cout << "Heap is empty" << endl;
                return;
            }

            cout << "Maximum Heap : ";
            for(int i = 0; i < heap_size; ++i){
                cout << heap[i] << " ";
            }cout << endl;
        }
        int get_max(){
            if(heap_size == 0){
                cout << "Heap is empty" << endl;
                return -1;
            }
            return heap[0];
        }
        int extract_max(){
            if(heap_size == 0){
                cout << "Heap is empty" << endl;
                return -1;
            }
            
            swap(heap[0], heap[heap_size - 1]);
            --heap_size;
            heapify(0);
            
            return heap[heap_size];
        }
        void decrease_key(int index, int val){
            if(index >= heap_size){
                cout << "Not enough elements" << endl;
                return;
            }
            
            heap[index] = val;
            while(index != 0 && heap[get_parent(index)] < heap[index]){
                swap(heap[get_parent(index)], heap[index]);
                index = get_parent(index);
            }
            
        }
        void delete_key(int index){
            if(index >= heap_size){
                cout << "Not enough elements" << endl;
                return;
            }

            decrease_key(index, INT_MAX);
            extract_max();
        }
};

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    
    int n;      cin >> n;
    max_heap *obj = new max_heap(n);

    int choice;     char ch;
    do{
        cout << "---- Main Menu ----" << endl;
        cout << " 1. Insert " << endl;
        cout << " 2. Print " << endl;
        cout << " 3. Get Maximum " << endl;
        cout << " 4. Extract Maximum " << endl;
        cout << " 5. Decrease key " << endl;
        cout << " 6. Delete Key " << endl;
        cout << " > Enter your choice : ";
        
        int choice;         cin >> choice;
        cout << endl << endl << "-----------------------------" << endl;
        if(choice == 1){
            int ele;        cin >> ele;
            obj->insert(ele);
        } else if(choice == 2){
            obj->print();
        } else if(choice == 3){
            cout << "- Get Maximum : " << obj->get_max() << endl;
        } else if(choice == 4){
            cout << "- Extract Maximum : " << obj->extract_max() << endl;
        } else if(choice == 5){
            cout << "Enter index and val : " ;
            int index, val;         cin >> index >> val;
            obj->decrease_key(index, val);
        } else if(choice == 6){
            cout << "Enter index  : " ;
            int index;         cin >> index;
            obj->delete_key(index);
            cout << endl;
        } else{
            cout << "Wrong choice !!!" << endl;
        }
        
        cout << "-----------------------------" << endl;
        cout << endl << "To continue press y : ";
        cin >> ch;         cout << endl << endl; 
    
    }while(ch == 'y' || ch == 'Y');


    return 0;
}

