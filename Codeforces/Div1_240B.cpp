#include <bits/stdc++.h>
#define mod 1000000007

using namespace std;

typedef long long int ll;

int main() {

    ll n, k, i, j, soma,  f;

    scanf("%lld%lld",&n,&k);

    vector< vector<ll> > mapa(n+2,vector<ll>(2000,-1));
    

    for( i=1; i<=n; i++ ) {
        f = 0;
        for( j=1; j<=sqrt(i); j++ ) {
            if( i%j==0 ) {
                mapa[i][f] =  j;
                f++;
                if( i/j != j ) {
                    mapa[i][f] =  i/j;
                    f++;
                }
            }
        }    
    } 
   
    vector< vector<ll> > dp(n+2, vector<ll>(k+2,0));
 
    for( i=1; i<=n; i++ ) {
        dp[i][1] = 1; 
    }

    for( i=1; i<=n; i++ ) {
        for( j=2; j<=k; j++ ) {
            f=0;
            while( mapa[i][f]!=-1 ) {
                dp[i][j] = (dp[i][j] + dp[mapa[i][f]][j-1] )%mod;
                f++;
            }
        }          
    }
    soma = 0;
    for( i=1; i<=n; i++ ) {
        soma = (dp[i][k]+soma)%mod;
    } 
    printf("%lld\n",soma);
    
    return 0;
}
