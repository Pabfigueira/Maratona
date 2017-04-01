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

    int n, m, k, i, j, h, ant, pos;

    scanf("%d %d %d",&n,&m,&k);

    vector<int> vetor(n);

    vector< vector< vector< vector<ll> > > > dp(2, vector< vector< vector<ll> > > (2, vector< vector<ll> >(m+1, vector<ll>(k+1,0))) );

    for( i=0; i<n; i++ ) {
        scanf("%d",&vetor[i]);
    }

    for( i=1; i<=n; i++ ) {
        for( h=1; h<=k; h++ ) {
            for( j=1; j<=m; j++ ) {
                if( i%2==1 ) { ant = 0; pos = 1; }
                else { ant=1; pos=0; } 

                dp[pos][0][j][h] = max(dp[ant][0][j][h], dp[ant][1][j][h]);
                if( j==1 )  dp[pos][1][j][h] = vetor[i-1] + max(dp[ant][0][m][h-1], dp[ant][1][m][h-1]);
                else        dp[pos][1][j][h] = vetor[i-1] + dp[ant][1][j-1][h];
            }
        }
    }

    printf("%lld\n",max(dp[n%2][1][m][k], dp[n%2][0][m][k]));

    return 0;
}
