#include <iostream>
#include <cmath>

using namespace std;

void solve(int n){
    if(n == 0 || n == 1){
        cout << n << endl;
        return;
    }

    int a = 0, b = 1, c = 1;
    while(--n){
        c = a + b;
        a = b;      b = c;
    }
    cout << a << endl;
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int t;      cin >> t;
    while(t--){
        int n;      cin >> n;
        solve(n);
    }

    return 0;
}
