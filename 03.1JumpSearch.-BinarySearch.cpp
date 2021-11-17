#include <iostream>
#include <cmath>

using namespace std;

void solve(int *array, int n, int k){
    int last_index = 0, jump = sqrt(n), curr_index = jump;

    int counter = 0;
    while(array[min(curr_index, n)-1] < k){
        last_index = curr_index;
        curr_index += jump;
        
        ++counter;
        if(curr_index >= n){
            break;
        }
    }
    
    curr_index = min(curr_index, n-1);
    while(last_index <= curr_index){
        ++counter;
        int mid = last_index + (curr_index - last_index)/2;

        if(array[mid] == k){
            cout << "Element found " << counter << endl;
            return;
        } else if(array[mid] < k){
            last_index = mid + 1;
        } else{
            curr_index = mid - 1;
        }
    }
    cout << "Element not found" << endl;

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
        solve(array, n, k);
    }

    return 0;
}
