#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {

    ll n, i, maximo;
    
    scanf("%lld",&n);

    vector<ll> dp(n+5,0);
    vector<ll> vetor(n+5,0);

    for( i=0; i<n; i++ ) {
        scanf("%lld",&vetor[i]);
    }

    maximo = 0;

    for( i=n-1; i>=0; i-- ) {
        dp[vetor[i]] = dp[vetor[i]+1] + 1;
        maximo = max(maximo,dp[vetor[i]]);
    }
    
    printf("%lld\n",n-maximo);
    return 0;
}
