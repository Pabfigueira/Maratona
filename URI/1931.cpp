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

ll Dijkstra( vector< vector< pair<ll,ll> > > *grafo, ll start, ll end ) {
    priority_queue< pair<ll,ll>, vector< pair<ll,ll> >, greater< pair<ll,ll> > > nodes;
    pair<ll,ll> atual;
    vector<ll> pesos(grafo->size(), LINF);

    pesos[start] = 0;
    nodes.push( make_pair(0,start) );

    while( !nodes.empty() ) {
        atual = nodes.top();
        nodes.pop();

        if( atual.second==end ) break;
        
        for( vector< pair<ll,ll> >::iterator it = (*grafo)[atual.second].begin(); it!=(*grafo)[atual.second].end(); ++it ) {
            if( pesos[it->second] == -1 || pesos[it->second] > it->first+pesos[atual.second] ) {
                pesos[it->second] = it->first + pesos[atual.second];
                nodes.push( make_pair(pesos[it->second], it->second) );
            }
        }
    }

    if( pesos[end] != LINF ) return pesos[end];
    return -1; 
}

int main() {
    BUFF;
    ll c, v, i, a, b, cost;

    cin >> c >> v;

    vector< vector<pair<ll,ll> > > graph(4*c);

    for( i=0; i<v; i++ ) {
        cin >> a >> b >> cost;
        graph[2*a].push_back( make_pair(cost,2*b+1) );
        graph[2*a+1].push_back( make_pair(cost,2*b) );

        graph[2*b].push_back( make_pair(cost,2*a+1) );
        graph[2*b+1].push_back( make_pair(cost,2*a) );
    }
    
    cout << Dijkstra(&graph,2*1,2*c) << endl; 

    return 0;
}
