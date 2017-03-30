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
#define NINF numeric_limits<ll>::min()
ll max3( ll a, ll b, ll c ) {
    if( a>=b && a>=c ) return a;
    if( b>=a && b>=c ) return b;
    return c;
}

ll max4( ll a, ll b, ll c, ll d ) {
    if( a>=b && a>=c && a>=d ) return a;
    if( b>=a && b>=c && b>=d ) return b;
    if( c>=a && c>=b && c>=d ) return c;
    return d;
}

int main() {
    ll n, i;

    scanf("%lld",&n);
        
    vector<ll> vetor(n);
    vector<ll> dif(n-1);

    for( i=0; i<n; i++ ) {
        scanf("%lld",&vetor[i]);
        if( i!=0 ) {
            dif[i-1] = abs(vetor[i-1] - vetor[i]);
        }
    }
    
    vector< vector< vector< vector<ll> > > > dp (n+5, vector<vector<vector<ll> > >(2, vector<vector<ll> >(2, vector<ll>(2,0)))); 

    // Ele é positivo
    // Ele esta no intervalo
    // Ja terminou o intervalo

    for( i=1; i<=n-1; i++ ) {
        dp[i][0][0][0] = max( dp[i-1][0][0][0], dp[i-1][1][0][0] );
        dp[i][0][0][1] = max4( dp[i-1][0][0][1], dp[i-1][1][0][1], dp[i-1][0][1][0], dp[i-1][1][1][0] ); 
        dp[i][0][1][0] = dif[i-1] + max3( dp[i-1][1][0][0], dp[i-1][0][0][0], dp[i-1][1][1][0] );
        //dp[i][0][1][1] = Nao existe;
        dp[i][1][0][0] = max( dp[i-1][0][0][0], dp[i-1][1][0][0] );
        dp[i][1][0][1] = max4( dp[i-1][0][0][1], dp[i-1][1][0][1], dp[i-1][0][1][0], dp[i-1][1][1][0] );
        dp[i][1][1][0] = -dif[i-1] + max3( dp[i-1][1][0][0], dp[i-1][0][0][0], dp[i-1][0][1][0] );
        //dp[i][1][1][1] = Nao Existe;
    }
    printf("%lld\n", max4(dp[n-1][0][0][1], dp[n-1][0][1][0], dp[n-1][1][0][1], dp[n-1][1][1][0]) );
    return 0;
}
