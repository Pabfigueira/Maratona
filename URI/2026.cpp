#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ll G, P, W, a, i, j;
    vector<ll> gains;
    vector<ll> costs;
    vector<ll> dp;

    scanf("%lld",&G);
    for(a=0; a<G; a++) {
        scanf("%lld%lld",&P,&W);

        gains.clear();
        gains.resize(P); 

        dp.clear();
        dp.resize(W+5,0);

        costs.clear();
        costs.resize(P);

        for(i=0; i<P; i++) {
            scanf("%lld%lld",&gains[i],&costs[i]);
        }

        for(j=0; j<P; j++) {
            for(i=W; i>=0; i--) {
                if(i>=costs[j]) {
                    dp[i] = max(dp[i],gains[j] + dp[i-costs[j]]);
                }
            }
        }
        printf("Galho %lld:\nNumero total de enfeites: %lld\n\n",a+1,dp[W]);
    }    
    return 0;
}
