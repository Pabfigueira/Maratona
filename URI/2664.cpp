#include<bits/stdc++.h>
#define MOD 1000000007ll

using namespace std;

typedef long long ll;

int main() {
    ll t, mini, maxi, i, j, total;
    scanf("%lld%lld%lld",&t,&mini,&maxi);
    
    vector<vector<ll>> dp(t+5,vector<ll>(maxi+5,0));

    for(j=mini; j<=maxi; j++) {
        dp[0][j] = 1;
    }

    for(i=1; i<t; i++) {
        for(j=mini; j<=maxi; j++) {
            dp[i][j] = (dp[i-1][j-1] + dp[i-1][j+1])%MOD;
        }
    }
    
    total = 0;
    for(j=mini; j<=maxi; j++) {
        total = (total + dp[t-1][j])%MOD;
    }
   
    printf("%lld\n",total);

    return 0;
}
