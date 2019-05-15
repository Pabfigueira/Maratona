#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define MOD 100000000

vector<vector<vector<vector<ll>>>> dp(101,vector<vector<vector<ll>>>(101,vector<vector<ll>>(11,vector<ll>(11,-1))));

ll n1,  n2, k1, k2;

ll solve(ll typeOne, ll typeTwo, ll nk1, ll nk2) {
    if(dp[typeOne][typeTwo][nk1][nk2]!=-1) return dp[typeOne][typeTwo][nk1][nk2];

    if(typeOne==0 and typeTwo==0) return 1;
    if(typeOne==0) {
        if(nk2==k2) return 0;
        return dp[typeOne][typeTwo][nk1][nk2] = solve(typeOne,typeTwo-1,0,nk2+1)%MOD;
    }
    if(typeTwo==0) {
        if(nk1==k1) return 0;
        return dp[typeOne][typeTwo][nk1][nk2] = solve(typeOne-1,typeTwo,nk1+1,0)%MOD;    
    }
    if(nk2==k2 and nk1==k1) return 0;
    if(nk2==k2) return dp[typeOne][typeTwo][nk1][nk2] = solve(typeOne-1,typeTwo,nk1+1,0)%MOD;
    if(nk1==k1) return dp[typeOne][typeTwo][nk1][nk2] = solve(typeOne,typeTwo-1,0,nk2+1)%MOD;
    return dp[typeOne][typeTwo][nk1][nk2] = (solve(typeOne-1,typeTwo,nk1+1,0) + solve(typeOne,typeTwo-1,0,nk2+1))%MOD;
}

int main() {
    scanf("%lld%lld%lld%lld",&n1,&n2,&k1,&k2);
    printf("%lld\n",solve(n1,n2,0,0));
    return 0;
}
