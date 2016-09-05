#include <bits/stdc++.h> 

using namespace std;

int main() {
    
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n;

    vector<int> fib(51);

    fib[0] = 1;
    fib[1] = 1; 

    for( n=2; n<=50; n++ ) {
        fib[n] = fib[n-1]+fib[n-2];
    }

    while( cin >> n && n ) {
        cout << fib[n] << '\n';
    }
    return 0;
}
