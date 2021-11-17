#include <iostream>
#include <cmath>

using namespace std;

void solve(int *array, int n, int k){
    int last_index = 0, jump = sqrt(n), curr_index = 0;

    int counter = 0;
    while(array[min(curr_index, n)-1] < k){
        last_index = curr_index;
        curr_index += jump;
        
        ++counter;
        if(curr_index >= n){
            break;
        }
    }

    while(last_index < n){
        if(array[last_index] == k){
            cout << "Element found at " << counter << endl;
            return;
        }
        ++counter;        ++last_index;
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
