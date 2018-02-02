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
#define imprime(x, Y)                              \
		for (int X = 0; X < Y; X++) cerr << x[X] << " "; \
cerr << endl;
#define ler freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);

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
    int n, i, atual, ant;

    scanf("%d",&n);

    vector< vector<int > >dp(2,vector<int>(4,0));
        
    dp[0][3] = 1;

    for( i=1;i<=n;i++ ) {
        if( i%2==0 ) {
            atual = 0; ant=1;
        } else {
            atual = 1; ant=0;
        }
        dp[atual][0] = ( ((dp[ant][1] + dp[ant][2])%MOD) + dp[ant][3])%MOD;
        dp[atual][1] = ( ((dp[ant][0] + dp[ant][2])%MOD) + dp[ant][3])%MOD;
        dp[atual][2] = ( ((dp[ant][0] + dp[ant][1])%MOD) + dp[ant][3])%MOD;
        dp[atual][3] = ( ((dp[ant][0] + dp[ant][1])%MOD) + dp[ant][2])%MOD;
    }
    printf("%d\n",dp[atual][3]);
	return 0;
}
