#include<bits/stdc++.h>

#define MAXSIZE 30001

using namespace std;

typedef int ll;

ll k;
vector<vector<ll>> dp(MAXSIZE+1,vector<ll>(506,-1));
vector<ll> arr(MAXSIZE+1);

ll solve(ll index, ll jump) {
    if(index>MAXSIZE) return 0;
    ll tradution = jump-(k-246);
    if(dp[index][tradution]!=-1) return dp[index][tradution];
    if(jump==1) return dp[index][tradution] = arr[index] + max(solve(index+jump,jump),solve(index+jump+1,jump+1));
    return dp[index][tradution] = arr[index] + max(solve(index+jump-1,jump-1),max(solve(index+jump,jump),solve(index+jump+1,jump+1)));
}

int main() {
    ll n, i, num;
    scanf("%d%d",&n,&k);    
    for(i=0; i<n; i++) {
        scanf("%d",&num);
        arr[num]++;
    }
    printf("%d\n",solve(k,k));
    return 0;
}
