#include <iostream>
#include <cmath>

using namespace std;

void merge(int *array, int low, int mid, int high){
    int n1 = mid - low + 1, n2 = high - mid;
    
    int *left = new int[n1], *right = new int[n2];
    for(int i = 0; i < n1; ++i){
        left[i] = array[low + i];
    }
    for(int i = 0; i < n2; ++i){
        right[i] = array[mid + 1 + i];
    }

    int i = 0, j = 0, k = low;
    while(i < n1 && j < n2){
        if(left[i] > right[j]){
            array[k++] = right[j++];
        } else if(left[i] < right[j]){
            array[k++] = left[i++];
        }
    }
    while(i < n1){
        array[k++] = left[i++];
    }
    while(j < n2){
        array[k++] = right[j++];
    }
}

void solve(int* array, int low, int high){
    if(low >= high){
        return;
    }

    int mid = low + (high - low)/2;

    solve(array, low, mid);
    solve(array, mid + 1, high);
    
    merge(array, low, mid, high);
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
        solve(array, 0, n-1);

        cout << "Sorted Array : ";
        for(int i = 0; i < n; ++i){
            cout << array[i] << " ";
        }cout << endl;
    }

    return 0;
}
