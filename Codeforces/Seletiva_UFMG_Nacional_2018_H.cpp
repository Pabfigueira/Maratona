#include <bits/stdc++.h>

#define modulo 998244353

using namespace std;

typedef long long int ll;

int main() {
    ll n, mod, m, i, x, total, j, antigo, novo;

    vector<ll> info;
    vector<ll> badinfo; 
    vector<ll> accumulated;

    scanf("%lld%lld",&n,&mod);

    info.resize(n);    
    accumulated.resize(mod,0);

    for( i=0; i<n; i++ ) {
        scanf("%lld",&info[i]);
    }

    scanf("%lld",&m);

    badinfo.resize(m);
    
    for( i=0; i<m; i++ ) {
        scanf("%lld",&badinfo[i]);
    }

    scanf("%lld",&x);

    total = 0;

    
    vector< vector<ll> > dp(n+5,vector<ll>(mod+5,0));

    for( i=0; i<n; i++ ) {
        dp[i][info[i]%mod] = 1;
        if( i==0 ) accumulated[info[i]%mod] = 1;
    }


    for( i=1; i<n; i++ ) {
        vector<ll> forsum(mod,0);
        for( antigo=0; antigo<mod; antigo++ ) {
            novo = (antigo*info[i])%mod;
            forsum[novo] = (forsum[novo]+accumulated[antigo])%modulo;
            dp[i][novo] = (dp[i][novo]+accumulated[antigo])%modulo;
        }
        for( j=0; j<mod; j++ ) {
            accumulated[j] = (accumulated[j]+forsum[j])%modulo;
        }
        accumulated[info[i]%mod] = (accumulated[info[i]%mod]+1)%modulo;
    }

    for( i=0; i<m; i++ ) {
        if( badinfo[i]%mod==x ) total = (total+1)%modulo;
        for( j=0; j<mod; j++ ) {
            if( (badinfo[i]*j)%mod==x ) {
                total = (total+accumulated[j])%modulo;  
            }
        }
    }


    printf("%lld\n",total);

    return 0;
}
