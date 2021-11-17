#include <iostream>
#include <climits>

using namespace std;

class min_heap{
    private:
        int *heap, capacity, heap_size;
    
    public:
        min_heap(int capacity){
            this->capacity = capacity;
            heap = new int[capacity];
            heap_size = 0;
        }
        void insert(int ele){
            if(heap_size == capacity){
                cout << "Heap is full" << endl;
                return;
            }

            int index = heap_size, parent = get_parent(index);
            ++heap_size;

            heap[index] = ele;
            while(index != 0 && heap[parent] > heap[index]){
                swap(heap[parent], heap[index]);
                index = get_parent(index);
                parent = get_parent(index);
            }
        }
        void print(){
            cout << "Min Heap : ";
            for(int i = 0; i < heap_size; ++i){
                cout << heap[i] << " ";
            } cout << endl;
        }
        void heapify(int index){
            int minimum = index, left = get_left_child(index), right = get_right_child(index);
            if(left < heap_size && heap[left] < heap[minimum]){
                minimum = left;
            }
            if(right < heap_size && heap[right] < heap[minimum]){
                minimum = right;
            }

            if(minimum != index){
                swap(heap[index], heap[minimum]);
                heapify(minimum);
            }
        }
        int get_min(){
            if(heap_size == 0){
                cout << "Heap is empty" << endl;
                return -1;
            }
            return heap[0];
        }
        int extract_min(){
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
                cout << "Not Enough ELements" << endl;
                return;
            }

            heap[index] = val;
            while(index != 0 && heap[index] < heap[get_parent(index)]){
                swap(heap[index], heap[get_parent(index)]);
                index = get_parent(index);
            }
        }
        void delete_key(int index){
            if(index >= heap_size){
                cout << "Not Enough ELements" << endl;
                return;
            }

            decrease_key(index, INT_MIN);
            extract_min();
        }

        int get_parent(int i){
            return ((i-1)/2);
        }
        int get_left_child(int i){
            return (2*i + 1);
        }
        int get_right_child(int i){
            return (2*i + 2);
        }
        
};

int main(){
    #ifndef ONLINE_JDUGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int n;      cin >> n;
    min_heap *obj = new min_heap(n);

    int choice;     char ch;
    do{
        cout << "---- Main Menu ----" << endl;
        cout << " 1. Insert " << endl;
        cout << " 2. Print " << endl;
        cout << " 3. Get Minimum " << endl;
        cout << " 4. Extract Minimum " << endl;
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
            cout << "- Get Minimum : " << obj->get_min() << endl;
        } else if(choice == 4){
            cout << "- Extract Minimum : " << obj->extract_min() << endl;
        } else if(choice == 5){
            cout << "Enter index and val : " ;
            int index, val;         cin >> index >> val;
            obj->decrease_key(index, val);
            cout << endl;
        } else if(choice == 6){
            cout << "Enter index  : " ;
            int index;         cin >> index;
            obj->delete_key(index);
            cout << endl;
        }  else{
            cout << "Wrong choice !!!" << endl;
        }
        
        cout << "-----------------------------" << endl;
        cout << endl << "To continue press y : ";
        cin >> ch;         cout << endl << endl; 
    
    }while(ch == 'y' || ch == 'Y');

    return 0;
}
