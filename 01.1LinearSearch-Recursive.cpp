#include <iostream>

using namespace std;

void linear_search(int *array, int n, int key){
    if(n == 0){
        cout << "Element not found" << endl;
        return;
    }

    if(array[n-1] == key){
        cout << "Element found at index " << n - 1 << endl;
    } 
    else{
        return linear_search(array, n-1, key);
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
        
        int key;        cin >> key;
        linear_search(array, n, key);

    }

    return 0;
}
