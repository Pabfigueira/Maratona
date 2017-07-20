#include <bits/stdc++.h>

using namespace std;

#define sc(a) scanf("%d", &a)
#define sc2(a,b) scanf("%d%d", &a, &b)
#define sc3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define scs(a) scanf("%s", a)
#define pri(x) printf("%d\n",x)
#define pri2(x,y) printf("%d %d\n", x, y)
#define prie(x) printf("%d ", x)
#define mp make_pair
#define pb push_back
#define BUFF ios::sync_with_stdio(false)
#define f first
#define s second

typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vector<ii> > vvii;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<ull> vull;
typedef vector<vull> vvull;

const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3fll;
const ld pi = acos(-1);
const int MOD = 1e9+7;
string word;
ll tam;

bool isHill() {
    bool fall = false;
    for( ll i=1;i<tam; i++ ) {
        if( word[i] < word[i-1] ) fall = true;
        else if( word[i] > word[i-1] ) {
            if( fall ) return false;
        }
    } 
    return true;
}

ll solve() {
    vector< vector< vector< vector<ll> > > > dp( tam+1, vector< vector< vector<ll> > >(10,vector< vector<ll> >(2,vector<ll>(2,0) ) ) );
    ll i, j, k;

    for( i=0; i<(word[0]- '0'); i++ ) {
        dp[1][i][1][0] = 1;
    }
    dp[1][word[0]-'0'][0][0] = 1;

    for( i=2; i<=tam; i++ ) {

        for( j=0; j<=9; j++ ) {
            
            if( j > (word[i-1] - '0')) {
                for( k=0; k<=9; k++ ) {
                    if( j<k )  dp[i][j][1][1] += dp[i-1][k][1][0] + dp[i-1][k][1][1];
                    if( j>k )  dp[i][j][1][0] += dp[i-1][k][1][0];
                    if( j==k ) {
                        dp[i][j][1][1] += dp[i-1][k][1][1];
                        dp[i][j][1][0] += dp[i-1][k][1][0];
                    }
                }                   
            }           

            if( j < ( word[i-1] - '0')) {
                for( k=0; k<=9; k++ ) {
                    if( j<k )  dp[i][j][1][1] += dp[i-1][k][1][0] + dp[i-1][k][0][0] + dp[i-1][k][1][1] + dp[i-1][k][0][1];
                    if( j>k )  dp[i][j][1][0] += dp[i-1][k][1][0] + dp[i-1][k][0][0];
                    if( j==k ) {
                        dp[i][j][1][0] += dp[i-1][k][1][0] + dp[i-1][k][0][0];
                        dp[i][j][1][1] += dp[i-1][k][1][1] + dp[i-1][k][0][1];
                    }
                }               
            }

            if( j==(word[i-1]-'0')) {
                for( k=0; k<=9; k++ ) {
                    if( j<k )  dp[i][j][0][1] += dp[i-1][k][0][0] + dp[i-1][k][0][1];
                    if( j>k )  dp[i][j][0][0] += dp[i-1][k][0][0];
                    if( j==k ) {
                        dp[i][j][0][1] += dp[i-1][k][0][1];
                        dp[i][j][0][0] += dp[i-1][k][0][0];
                    }
                
                    if( j<k )  dp[i][j][1][1] += dp[i-1][k][1][0] + dp[i-1][k][1][1];
                    if( j>k )  dp[i][j][1][0] += dp[i-1][k][1][0];
                    if( j==k ) {
                        dp[i][j][1][0] += dp[i-1][k][1][0];
                        dp[i][j][1][1] += dp[i-1][k][1][1];
                    }
                }   
            }
        }
    }   

    /*for( i=0; i<=tam; i++ ) {
        for( j=0; j<=1; j++ ) {
            cout << "dp[" << i << "][" << j << "][0][0] " << dp[i][j][0][0] << endl;
            cout << "dp[" << i << "][" << j << "][0][1] " << dp[i][j][0][1] << endl;
            cout << "dp[" << i << "][" << j << "][1][0] " << dp[i][j][1][0] << endl;
            cout << "dp[" << i << "][" << j << "][1][1] " << dp[i][j][1][1] << endl;
        }
    }*/

    ll soma = 0;
    for( i=0; i<=9; i++ ) {
        soma += dp[tam][i][1][0] + dp[tam][i][1][1];
    }
    return soma;
}


int main() {
    
    BUFF;

    ll n;
    cin >> n;

    while( n-- ) {
        cin >> word;
        tam = word.size();
        if( isHill() ) {
            cout << solve() << endl;
        } else {
            cout << -1 << endl;
        }
    }
    return 0;
}
