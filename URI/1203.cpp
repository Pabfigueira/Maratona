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

vector<int> moedas;
vector<int> dp;

int main() {
    int r, k, i, a, b, j;
    
    while( cin >> r >> k && cin ) {
        dp.clear();
        dp.resize(k+1,INF);
        moedas.clear();
        moedas.resize(r,0);

        for( i=0; i<k; i++ ) {
            cin >> a >> b;
            a--; b--;
            moedas[a]++;
            moedas[b]++; 
        }

        dp[0] = 0;

        for( i=0; i<r; i++ ) {
            for( j=k; j>=0; j-- ) {
                if( j-moedas[i]>=0 and dp[j-moedas[i]]+1 < dp[j] ) {
                    dp[j] = dp[j-moedas[i]]+1;
                }
            }
        }
        if( dp[k]!=INF ) cout << "S\n";
        else cout << "N\n"; 
    }
	
	return 0;
}
