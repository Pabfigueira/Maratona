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

void dijkstra( ll source, ll destiny, vector< vector<pair<ll,ll> > >& graph, vector<ll>& cost ) {
    priority_queue< pair<ll,ll>, vector< pair<ll,ll> >, greater< pair<ll,ll> > > fila;

    pair<ll,ll> atual;

    cost[source] = 0;

    fila.push( mp(0,source) );

    while( !fila.empty() ) {
        atual = fila.top();
        fila.pop();

        for( int i=0; i<graph[atual.second].size(); i++ ) {
            if( cost[graph[atual.second][i].first] > graph[atual.second][i].second + cost[atual.second] ) {
                cost[graph[atual.second][i].first] = graph[atual.second][i].second + cost[atual.second];
                fila.push( make_pair(cost[graph[atual.second][i].first],graph[atual.second][i].first) );
            }  
        } 
    }  
}


int main() {
    vector< vector< pair<ll,ll> > > graphA;
    vector<ll> costA;

    vector< vector< pair<ll,ll> > > graphB;
    vector<ll> costB;

    ll n, m, i, a, b, c, d;

    while( scanf("%lld%lld",&n,&m) != EOF ) {

        graphA.clear();
        graphA.resize(n);
        costA.clear();
        costA.resize(n,LINF);

        graphB.clear();
        graphB.resize(n);
        costB.clear();
        costB.resize(n,LINF);


        for( i=0; i<m; i++ ) {
            scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
            a--; b--;

            if( c==0 ) {
                graphA[a].push_back( make_pair(b,d) );
            } else {
                graphB[a].push_back( make_pair(b,d) );
            }
        }

        dijkstra(0,n-1,graphA,costA);
        dijkstra(0,n-1,graphB,costB);

        if( costA[n-1]==LINF )  printf("%lld\n",costB[n-1]);
        else if( costB[n-1]==LINF ) printf("%lld\n",costA[n-1]);
        else if( costA[n-1] < costB[n-1] ) printf("%lld\n",costA[n-1]);
        else printf("%lld\n",costB[n-1]);
    }
	return 0;
}
