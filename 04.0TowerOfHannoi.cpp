#include <iostream>
#include <cmath>

using namespace std;

void solve(int n, char source, char aux, char dest){
    if(n == 1){
        cout << "Moving disk from " << source << " to " << dest << endl;
        return;
    }
    solve(n-1, source, dest, aux);
    cout << "Moving disk from " << source << " to " << dest << endl;
    solve(n-1, aux, source, dest);
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int n;      cin >> n;
    solve(n, 'A', 'B', 'C');

    return 0;
}
