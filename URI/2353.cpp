#include <bits/stdc++.h> 

using namespace std;

bool is_prime( long long int n ) {

    for(long long int i=2; i<=sqrt(n);i++ ) {
        if( n%i==0 ) return false;
    }
    return true;
}

int main() {
    
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    long long int n;    

    cin >> n;

    while( !is_prime(n) ) {
        n--;
    }
    cout << n << endl;
    return 0;
}
