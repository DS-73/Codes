#include <iostream>
#include <queue>

using namespace std;

void print_max(priority_queue<int> heap){
    priority_queue<int> temp_heap = heap;

    cout << "Maximum Heap : ";
    while(!temp_heap.empty()){
        cout << temp_heap.top() << " ";
        temp_heap.pop();
    } cout << endl;
}

void print_min(priority_queue<int, vector<int>, greater<int>> heap){
    priority_queue<int, vector<int>, greater<int>> temp_heap = heap;

    cout << "Mainimum Heap : ";
    while(!temp_heap.empty()){
        cout << temp_heap.top() << " ";
        temp_heap.pop();
    } cout << endl;
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    priority_queue<int> max_heap;
    int n1;      cin >> n1;
    for(int i = 0; i < n1; ++i){
        int val;        cin >> val;
        max_heap.push(val);
    }
    print_max(max_heap);
    cout << "Top : " << max_heap.top() << endl;
    cout << "Empty : " << max_heap.empty() << endl;
    cout << endl;

    priority_queue<int, vector<int>, greater<int>> min_heap;
    int n2;      cin >> n2;
    for(int i = 0; i < n2; ++i){
        int val;        cin >> val;
        min_heap.push(val);
    }
    print_min(min_heap);        
    cout << "Top : " << min_heap.top() << endl;
    cout << "Empty : " << min_heap.empty() << endl;
    cout << endl;

    return 0;
}
