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

ll n, k, d;

map<pair<ll,ll>,ll> mapa;
map<pair<ll,ll>,ll>::iterator it;

ll solve( ll value, ll usedD ) {
    if( value==n and usedD==1 ) return 1;

    it = mapa.find( mp(value,usedD)  );
    if( it!=mapa.end() ) return it->second;
    
    ll soma = 0;

    for( ll i=1; i<=k; i++ ) {
        if( value+i <= n ) {
            if( usedD==1 or i>=d ) {
                soma = (soma + solve( value+i, 1 ))%MOD;
            } else {
                soma = (soma + solve( value+i, 0 ))%MOD;
            }    
        } 
    }
    return mapa[mp(value,usedD)] = (soma%MOD);
}

int main() {
    cin >> n >> k >> d;

    cout << solve(0,0) << endl;

	return 0;
}
