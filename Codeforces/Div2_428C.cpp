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

vector<vector<ll> > graph;
set<ll> visited;

double soma;

double dfs( ll node, ll deep ) {

    visited.insert(node);

    double visitou = 0;

    vector<double> parc;

    for( ll i=0; i<graph[node].size(); i++ ) {
        if( visited.find( graph[node][i] ) == visited.end() ) {
            visitou++;
            parc.pb(dfs( graph[node][i], deep+1 ));
        }
    }

    if( visitou==0 ) return deep;
    else {
        double prob = 1/visitou;
        double sum = 0;

        for( ll i=0; i<parc.size(); i++ ) {
            sum += prob*parc[i];
        }
        return sum;
    }
}

int main() {
    ll n, i, a, b;
    cin >> n;

    if( n==1 ) {
        cout << 0 << endl;
        return 0;
    }

    soma = 0;

    graph.resize(n);

    for( i=0; i<n-1; i++ ){
        cin >> a >> b;
        a--; b--;
        graph[a].pb(b);
        graph[b].pb(a);
    }

    soma = dfs(0,0);

    printf("%.10lf\n",soma);

    return 0;
}
