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
    ll m, i, j;
    cin >> m;

    vector<ll> moedas(2);
    moedas[0] = 4;
    moedas[1] = 7;

    vector<ll> dp(m+1,LINF);
    
    dp[0] = 0;

    for( i=1; i<=m; i++ ) {
        for( j=0; j<2; j++ ) {
            if( i-moedas[j]>=0 and dp[ i-moedas[j] ]!=LINF ) {
                dp[i] = min(dp[i],dp[ i-moedas[j] ] + 1 );
            }
        }
    }  
    if( dp[m]==LINF ) cout << -1 << endl;
    else {
        vector<int> resp;
        while( m!=0 ) {
            if( dp[m-4] ==  dp[m]-1 ) {
                resp.push_back(4);
                m-=4;
            } else {
                resp.push_back(7);
                m-=7;
            }
        }
        sort(resp.begin(),resp.end());
        for( i=0; i<resp.size(); i++) {
            cout << resp[i];
        }
        cout << endl;
    }
    return 0;
}
