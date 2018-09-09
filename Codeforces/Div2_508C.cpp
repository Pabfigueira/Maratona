#include <bits/stdc++.h> 

using namespace std;

typedef long long int ll;

vector<ll> A;
vector<ll> B;

ll n;

ll play( ll indexA, ll indexB, ll who ) {
    if( indexA == n and indexB == n ) return 0;
    
    if( indexA==n ) {
        if( who==0 ) return play(indexA,indexB+1,1);
        return -B[indexB]+play(indexA,indexB+1,0);
    }
    if( indexB==n ) {
        if( who==0 ) return A[indexA] + play(indexA+1,indexB,1);
        return play(indexA+1,indexB,0);
    }
    
    if( who==0 ) {
        if( A[indexA] >= B[indexB] ) return A[indexA]+play(indexA+1,indexB,1);
        return play(indexA,indexB+1,1);
    } else { 
        if( A[indexA] <= B[indexB] ) return -B[indexB]+play(indexA,indexB+1,0);
        return play(indexA+1,indexB,0);
    }
}

int main() {
        
    ll i;

    scanf("%lld",&n);

    A.resize(n);
    B.resize(n);

    for( i=0; i<n; i++ ) {
        scanf("%lld",&A[i]);
    }
    for( i=0; i<n; i++ ) {
        scanf("%lld",&B[i]);
    }

    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    reverse(A.begin(),A.end());
    reverse(B.begin(),B.end());

    printf("%lld\n",play(0,0,0)); 
    return 0;
}
