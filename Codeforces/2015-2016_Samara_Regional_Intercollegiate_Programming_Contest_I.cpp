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
    BUFF;

    ll n, d, c, i, j;

    cin >> n >> d >> c; 

    vector<ll> vetor(n);
    vector<ll> sum(n,0);
    vector<ll> dp(n+1,numeric_limits<ll>::max());
    dp[0] = 0;

    for( i=0; i<n; i++ ) {
        cin >> vetor[i];

        if( i>0 ) sum[i] = sum[i-1] + i*(vetor[i]-vetor[i-1]);
    }

    for( i=1; i<=n; i++ ) {
        for( j=0; j<i; j++ ) {
            dp[i] = min(dp[i], dp[j] + ((sum[i-1]-sum[j])-(j*(vetor[i-1]-vetor[j])))*c + d);
        }
    }
    
    cout << dp[n] << endl;
    return 0;
}
