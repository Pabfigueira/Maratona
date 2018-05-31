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
    ll n, i, j, menor;

    cin >> n;

    vector<ll> size(n);
    vector<ll> cost(n);

    for( i=0; i<n; i++ ) {
        cin >> size[i];
    }
    for( i=0; i<n; i++ ) {
        cin >> cost[i];
    }
    
    vector< vector<ll> > dp(n,vector<ll>(3,INF));
    
    for( i=0; i<n; i++ ) {
        dp[i][0] = cost[i];
    }

    for( i=0; i<n; i++ ) {
        for( j=0; j<i; j++ ) {
            if( size[i]>size[j] ) {
                dp[i][1] = min(dp[i][1], dp[j][0] + cost[i]);
                if( dp[j][1]!=INF ) dp[i][2] = min(dp[i][2],dp[j][1]+cost[i]);
            }    
        }
    } 
    menor = INF;
    for( i=0; i<n; i++ ) {
        menor = min(menor,dp[i][2]);        
    }
    if( menor==INF ) cout << "-1\n";
    else cout << menor << endl;
    return 0;
}
