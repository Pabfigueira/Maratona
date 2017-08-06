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

map<ll,ll> mapa;
map<ll,ll>::iterator it;

ll solve( ll num ) {
    it = mapa.find(num);
    if( it!=mapa.end() ) return it->second;

    ll res = num/2 + 1;

    for( ll i=2; i<=sqrt(num); i++ ) { 
        if( num%i==0 ) {
            ll qtd = i/2 + 1;
            res = min(res,qtd*solve(num/i));

            ll i2 = num/i;
            ll qtd2 = i2/2 + 1;
            res = min(res,qtd2*solve(i));
        }        
    }
    return mapa[num] = res;
}

int main() {
    ll n;
    cin >> n;

    cout << solve(n) << endl;
    return 0;
}
