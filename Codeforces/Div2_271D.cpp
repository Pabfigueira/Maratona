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
    ll t, k, i, a, b;

    scanf("%lld %lld",&t, &k);

    vector<int> dp(100005,0);
    vector<int> processed(100005,0);

    dp[0] = 1;

    for( i=1; i<k; i++ ) {
        dp[i] = 1;
        processed[i] = (processed[i-1] + dp[i]) % MOD;
    }
    
    for( i=k; i<=100003; i++ ) {
        dp[i] = (dp[i-1] + dp[i-k]) % MOD;
        processed[i] = (processed[i-1] + dp[i]) % MOD;
    }

    for( i=0; i<t; i++ ) {
        scanf("%lld %lld",&a,&b);
        cout << ((processed[b] - processed[a-1])+1000000007)%1000000007 << endl;
    }

    return 0;
}
