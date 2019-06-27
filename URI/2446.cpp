#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {

    ll v, m, i, j;
    scanf("%lld%lld",&v,&m);
    vector<ll> coins(m);
    for(i=0; i<m; i++) {
        scanf("%lld",&coins[i]);
    }

    vector<int> dp(v+5,0);
    dp[0] = 1;

    for(j=0; j<m; j++) {
        for(i=v; i>0; i--) {
            if(i>=coins[j]) {
                dp[i] = min(1,dp[i]+dp[i-coins[j]]);
            }
        }
    }
    if(dp[v]) printf("S\n");
    else printf("N\n");

    return 0;
}
