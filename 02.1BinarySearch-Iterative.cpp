#include <iostream>

using namespace std;

void binary_search(int *array, int n, int key){
    int low = 0, high = n - 1;
    while(low <= high){
        int mid = low + (high - low)/2;
        if(array[mid] == key){
            cout << "Element found at index " << mid << endl;
            return;
        } else if(array[mid] < key){
            low = mid + 1;
        } else{
            high = high + 1;
        }
    }
    cout << "Element not found " << endl;

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
        binary_search(array, n, key);
    }

    return 0;
}
