#include <iostream>

using namespace std;

int solve(int *array, int low, int high, int k){
    if(low > high){
        return -1;
    }

    int mid = low + (high - low)/2;
    if(array[mid] == k)             return mid;
    else if(array[mid] > k)         return solve(array, low, mid - 1, k);
    else                            return solve(array, mid + 1, high, k);
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

        int k;      cin >> k;
        int res = solve(array, 0, n-1, k);
        if(res == -1){
            cout << "Key not found" << endl;
        } else{
            cout << "Key found at " << res << endl;
        }

    }

    return 0;
}
