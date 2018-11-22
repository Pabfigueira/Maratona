#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main() {

    ll n, maximo, elemaximo, i, aux;

    scanf("%lld",&n);

    vector<ll> vetor(n);
    map<ll,ll> dp;

    for( i=0; i<n; i++ ) {
        scanf("%lld",&vetor[i]);
        dp[vetor[i]] = 0;
    }   
    maximo = 0;
    for( i=0; i<n; i++ ) {
        dp[vetor[i]] = dp[vetor[i]-1]+1;
        if( dp[vetor[i]] > maximo ) {
            maximo = dp[vetor[i]];
            elemaximo = i; 
        }
    }
    vector<ll> resp;
    printf("%lld\n",dp[vetor[elemaximo]]);
    while( true ) {
        resp.push_back(elemaximo);
        aux = elemaximo;
        if( maximo == 1 ) break;
        while( vetor[aux]!=vetor[elemaximo]-1 ) aux--;
        elemaximo = aux;
        maximo--;
    }
    reverse(resp.begin(),resp.end());
    for( i=0; i<(ll)resp.size(); i++ ) {
        if( i>0 ) printf(" ");
        printf("%lld",resp[i]+1);
    }
    printf("\n");
    return 0;
}
