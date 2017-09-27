#include <bits/stdc++.h>

using namespace std;

#define sc(a) scanf("%d", &a)
#define sc2(a, b) scanf("%d%d", &a, &b)
#define sc3(a, b, c) scanf("%d%d%d", &a, &b, &c)
#define scs(a) scanf("%s", a)
#define pri(x) printf("%d\n", x)
#define prie(x) printf("%d ", x)
#define mp make_pair
#define pb push_back
#define BUFF ios::sync_with_stdio(false);
#define db(x) cerr << #x << " == " << x << endl
#define dbs(x) cerr << x << endl
#define ler freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#define imprime(x, Y)                              \
  for (int X = 0; X < Y; X++) cerr << x[X] << " "; \
  cerr << endl;
typedef long long int ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vector<ii> > vvii;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const ld pi = acos(-1);
const int MOD = 1e9 + 7;

int main() {
    ll n, m, i, j, k, a, b, c, maximoLinha, minimoTotal;

    scanf("%lld%lld",&n,&m);

    vector< vector<ll> > dp(n+1,vector<ll>(n+1,LINF));

    for( i=0; i<n; i++ ) {
        dp[i][i] = 0;
    }
  
    for( i=0; i<m; i++ ) {
        scanf("%lld%lld%lld",&a,&b,&c);
        dp[a][b] = min(dp[a][b],c);
        dp[b][a] = min(dp[b][a],c);
    }

  
    for( k=0; k<n; k++ ) {
        for( i=0; i<n; i++ ) {
            for( j=0; j<n; j++ ) {
                if( dp[i][k]!=LINF and dp[k][j]!=LINF )
                    dp[i][j] = min(dp[i][j],dp[i][k]+dp[k][j]);    
            }    
        }    
    }

    minimoTotal = LINF;

    for( i=0; i<n; i++ ) {
        maximoLinha = 0;
        for( j=0; j<n; j++ ) {
            maximoLinha = max(maximoLinha,dp[i][j]);
        }    
        minimoTotal = min(minimoTotal,maximoLinha);
    } 
    printf("%lld\n",minimoTotal);
    return 0;
}

