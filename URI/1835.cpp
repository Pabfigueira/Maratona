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

vector<ll> p;

ll Find( ll a ) { return p[a] == a ? a : p[a] = Find(p[a]); }

void Union( ll a, ll b ) { p[Find(a)] = Find(b); }

int main() {
    BUFF;
    ll testes, t, i, n, m, a, b;

    cin >> t;
    set<ll> group;

    for( testes=1; testes<=t; testes++ ) {
        cout << "Caso #" << testes << ": ";
        cin >> n >> m;

        p.clear();
        group.clear();
        p.resize(n);

        for( i=0; i<n; i++ ) {
            p[i] = i;
        }

        for( i=0; i<m; i++ ) {
            cin >> a >> b;
            a--; b--; 
            if( Find(a)!=Find(b) ) {
                Union(a,b);
            }
        } 

        for( i=0; i<n; i++ ) {
            group.insert( Find(i) ); 
        } 
        if( group.size()==1 ) cout << "a promessa foi cumprida\n";
        else cout << "ainda falta(m) " << group.size()-1 << " estrada(s)\n";
    }

    return 0;
}
