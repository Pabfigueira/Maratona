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
    int n, i, resp, num;

    sc(n);

    vector< vector< vector<int> > > dp(n+5,vector< vector<int> >(2, vector<int>(2,0)));
       
    bool noZero = true;
 
    for( i=1; i<=n; i++ ) {
        sc(num);

        if( num==1 ) {
            dp[i][0][0] = 1 + dp[i-1][0][0];
            dp[i][0][1] = 1 + max( dp[i-1][0][1], dp[i-1][1][1] );
            dp[i][1][1] = max( dp[i-1][0][0], dp[i-1][1][1] );
        } else {
            noZero = false;
            dp[i][0][0] = dp[i-1][0][0]; 
            dp[i][0][1] = max( dp[i-1][0][1], dp[i-1][1][1] );
            dp[i][1][1] = 1 + max( dp[i-1][0][0], dp[i-1][1][1] );
        }       
    }
    
    if( noZero ) {
        pri(n-1);
        return 0;
    }

    resp = max(dp[n][0][0],dp[n][0][1]);
    resp = max(resp,dp[n][1][1]);
    pri(resp);
	return 0;
}
