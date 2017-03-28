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

ll min3( ll a, ll b, ll c  ){
    if( a<=b && a<=c ) return a;
    if( b<=a && b<=c ) return b;
    return c;
}

int main() {

    ll n, i;

    scanf("%lld",&n);

    vector<int> vetor(n+1,0);    
    vector< vector<ll> > dp(n+3,vector<ll>(3,LINF));


    dp[0][0] = 0;
    dp[0][1] = 0;
    dp[0][2] = 0;

    for( i=1; i<=n; i++ ) {
        scanf("%d",&vetor[i]);

        if( vetor[i] == 0 ) {
            dp[i][0] = min3(dp[i-1][0],dp[i-1][1],dp[i-1][2]) + 1;
        }
        if( vetor[i] == 3 ) {
            dp[i][0] = min3(dp[i-1][0],dp[i-1][1],dp[i-1][2]) + 1;
            dp[i][1] = min (dp[i-1][0],dp[i-1][2]);  
            dp[i][2] = min (dp[i-1][0],dp[i-1][1]);
        } 
        if( vetor[i] == 1 ) {
            dp[i][0] = min3(dp[i-1][0],dp[i-1][1],dp[i-1][2]) + 1;
            dp[i][1] = min(dp[i-1][0],dp[i-1][2]);
        }
        if( vetor[i] == 2 ) {
            dp[i][0] = min3(dp[i-1][0],dp[i-1][1],dp[i-1][2]) + 1;
            dp[i][2] = min(dp[i-1][0],dp[i-1][1]);
        }
    }

    printf("%lld\n",min3(dp[n][0],dp[n][1],dp[n][2])); 

	return 0;
}
