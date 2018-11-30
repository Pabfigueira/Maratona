#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ll n, i, extremo;

    scanf("%lld",&n);

    vector<ll> vetor(n);

    for( i=0; i<n; i++ ) {
        scanf("%lld",&vetor[i]);
    }

    extremo = 0;

    for( i=1; i<n-1; i++ ) {
        if( vetor[i] > vetor[i-1] and vetor[i] > vetor[i+1] ) extremo++;
        else if( vetor[i] < vetor[i-1] and vetor[i] < vetor[i+1] ) extremo++;        
    }

    printf("%lld\n",extremo);
    return 0;
}
