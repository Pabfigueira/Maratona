#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main() {

    ll n, t, i, j, maximo, teste;

    teste = 1;

    while( true ) {
        scanf("%lld %lld",&n,&t);
        if( n==0 ) break;         

        printf("Instancia %lld\n", teste++);
        vector<ll> dp(t+5,0);
        vector<ll> cost(n);
        vector<ll> gain(n);

        for( i=0; i<n; i++ ) {
            scanf("%lld %lld",&cost[i],&gain[i]);
        }

        dp[0] = 0; 
        maximo = 0;
        for( i=1; i<=t; i++ ) {
            for( j=0; j<n; j++ ) {
                if( i >= cost[j] ) {
                    dp[i] = max(dp[i], dp[i-cost[j]] + gain[j]); 
                    maximo = max(maximo,dp[i]);
                }
            }     
        }
        printf("%lld\n\n",maximo); 
    }
    return 0;
}
