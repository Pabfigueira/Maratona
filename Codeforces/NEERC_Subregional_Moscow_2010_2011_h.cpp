#include <bits/stdc++.h> 

using namespace std;

bool isPrime( long long int n ) { 
    if( n == 1 ) return false;
    if( n == 2 ) return true;
    for( long long int i=2; i<=sqrt(n); i++ ) {
        if( n%i==0 ) return false;
    } 
    return true;
}

int main() {
    
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    long long int n;
    
    cin >> n;
    
    if( n == 4 ) cout << "NO\n";
    else if( isPrime(n) ) cout << "NO\n";
    else cout << "YES\n";

    return 0;
}
