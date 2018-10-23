#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main() {

    ll n, index, soma, i, j;

    scanf("%lld%lld",&n,&index);
    index--;
    vector<ll> vetor(n);

    for( i=0; i<n; i++ ) {
        scanf("%lld",&vetor[i]);
        if( i==index ) soma = vetor[i];
    }

    i = index-1;
    j = index+1;

    while( true ) {
        if( i<0 and j>=n ) break;

        if( i<0 ) {
            soma += vetor[j];    
        } else if( j>=n ) {
            soma += vetor[i];
        } else {
            if( vetor[i]+vetor[j]==2 ) soma += 2; 
        }
        i--;
        j++;
    } 

    printf("%lld\n",soma);
    return 0;
}
