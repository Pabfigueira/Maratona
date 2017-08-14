#include <bits/stdc++.h>

using namespace std;

#define sc(a) scanf("%d", &a)
#define sc2(a, b) scanf("%d%d", &a,&b)
#define sc3(a, b, c) scanf("%d%d%d",&a, &b,&c)
#define scs( a ) scanf("%s", a)
#define pri(x) printf("%d\n", x)
#define prie(x) printf("%d ", x)
#define mp make_pair
#define pb push_back
#define BUFF ios::sync_with_stdio(false);
#define f first
#define s second

typedef long long int ll;
typedef long double ld;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vector<ii> > vvii;

const int inf = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const ld pi = acos(-1);
const int MOD = 1e9+7;

vector< vector< pair<ll,ll> > > grafo;

void Dijkstra( ll start, ll end, vector<ll>& pesos ) {
    priority_queue< pair<ll,ll>, vector< pair<ll,ll> >, greater< pair<ll,ll> > > nodes;

    pair<ll,ll> atual;

    pesos[start] = 0;
    nodes.push( make_pair(0, start));

    while( !nodes.empty() ) {
        atual = nodes.top();
        nodes.pop();

        for( vector<pair<ll,ll> >::iterator it = grafo[atual.second].begin(); it!=grafo[atual.second].end(); it++ ) {
            if( pesos[it->second] == -1 || pesos[it->second] > it->first+pesos[atual.second] ) {
                pesos[it->second] = it->first+pesos[atual.second];
                nodes.push( make_pair(pesos[it->second], it->second) );
            }
        }
    }

}



int main() {
    BUFF;

    ll n, m, x, i, a, b, c, minimo;

    cin >> n >> m >> x;

    grafo.resize(n);

    vector< ll > pesosA(n,LINF);
    vector< ll > pesosB(n,LINF);

    for( i=0; i<m; i++ ) {
        cin >> a >> b >> c;
        a--; b--;
        grafo[a].pb( mp(c,b) );
        grafo[b].pb( mp(c,a) );    
    }
    
    Dijkstra(0,n-1,pesosA);
    Dijkstra(n-1,0,pesosB);

    for( i=0; i<x; i++ ) {
        cin >> a;
        a--;
        if( i==0 ) minimo = pesosA[a] + pesosB[a];
        else {
            minimo = min(minimo,pesosA[a]+pesosB[a]);
        }
    }
    cout << minimo << endl;
    return 0;
}
