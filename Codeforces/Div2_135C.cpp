#include <bits/stdc++.h>

using namespace std;

#define INF numeric_limits<int>::max()

typedef long long int ll;

int main() {

    ios_base::sync_with_stdio(false);

    ll i, j, n, k, h, maximo, index;

    char letter;

    string resp;

    cin >> n >> k; 

    k = min(k+1,4ll);

    vector<ll> vetor(n);

    for( i=0; i<n; i++ ) {
        cin >> letter;
        vetor[i] = (ll)(letter - 'A');
    }
    
    vector< vector<ll> > dp(n+5, vector<ll>(k,INF));   
    vector< vector<ll> > veio(n+5, vector<ll>(k,-1));

    dp[0][0] = 0;
    for( j=1; j<k; j++ ) {
        dp[0][j] = 1;     
    } 

    for( i=1; i<n; i++ ) {
        for( j=0; j<k; j++ ) {
            for( h=0; h<k; h++ ) {
                if( h==0 and j==0 ) {
                    if( vetor[i]!=vetor[i-1] ) {
                        if( dp[i-1][h] < dp[i][j] ) {        
                            dp[i][j] = dp[i-1][h];
                            veio[i][j] = h;
                        }
                    }
                } else if( j==0 ) {
                    if( vetor[i]+1!=h ) {
                        if( dp[i-1][h] < dp[i][j] ) { 
                            dp[i][j] = dp[i-1][h];
                            veio[i][j] = h;
                        }
                    }
                } else if( h==0 ) {
                    if( j!=vetor[i-1]+1 ) {
                        if( dp[i-1][h]+1 < dp[i][j] ) {
                            dp[i][j] = dp[i-1][h]+1;
                            veio[i][j] = h; 
                        }
                    }   
                } else if( h!=j ) {
                    if( dp[i-1][h]+1 < dp[i][j] ) {
                        dp[i][j] = dp[i-1][h]+1;
                        veio[i][j] = h;
                    }    
                }                 
            }
        }
    }

    maximo = INF;
    for( i=0; i<k; i++ ) {
        if( maximo > dp[n-1][i] ) {
            maximo = dp[n-1][i];
            index = i;
        }
    }
    cout << maximo << endl;


    // Recovering answer
    i=n-1;
    while( i>=0 ) {
        if( index==0 ) resp += (char)(vetor[i]+'A');
        else resp += (char)(index-1+'A');
        index = veio[i][index];
        i--;
    }
    reverse(resp.begin(),resp.end());
    cout << resp << endl;
    return 0;
}
