#include <bits/stdc++.h>

using namespace std;

#define sc(a) scanf("%d", &a)
#define sc2(a, b) scanf("%d%d", &a, &b)
#define sc3(a, b, c) scanf("%d%d%d", &a, &b, &c)
#define scs(a) scanf("%s", a)
#define mp make_pair
#define pb push_back
#define BUFF ios::sync_with_stdio(false);
#define db(x) cerr << #x << " == " << x << endl
#define dbs(x) cerr << x << endl
#define ler freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#define imprime(x, Y)                              \
  for (ll X = 0; X < Y; X++) cerr << x[X] << " "; \
  cerr << endl;
typedef long long int ll;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef vector<ll> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vector<ii> > vvii;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const ld pi = acos(-1);
const int MOD = 1e9 + 7;

vector< vector< pair<ll,ll> > > graphC;
vector< pair<ll, pair<ll,ll> > > edges;

vector<ll> level;
vector<ll> minLevel;

vector<ll> res;

void Dijkstra( vector< vector<pair<ll,ll> > >& graph, ll start, ll end, vector<ll>& pesos ) {
    priority_queue< pair<ll,ll>, vector<pair<ll,ll> >, greater<pair<ll,ll> > > nodes;

    pesos[start] = 0; 
    nodes.push( mp(0,start) );  

    pair<ll,ll> atual;

    while( !nodes.empty() ) {

        atual = nodes.top();
        nodes.pop();

        for( vector<pair<ll,ll> >::iterator it=graph[atual.second].begin(); it!=graph[atual.second].end(); ++it ) {
            if( pesos[it->second] == -1 || pesos[it->second] > it->first + pesos[atual.second] ) {
                pesos[it->second] = it->first + pesos[atual.second];
                nodes.push( mp(pesos[it->second], it->second) );          
            }   
        }
    }
}

ll dfs( ll start, ll nivel, ll edgeDad ) {      
    if( level[start]!=-1 ) {
        if( minLevel[start]==
            LINF ) return level[start];
        else return minLevel[start];
    }

    level[start] = nivel;

    ll retorno, minimo = nivel;

    for( ll i=0; i<graphC[start].size(); i++ ) {
        if( graphC[start][i].second!=edgeDad ) {
            retorno = dfs( graphC[start][i].first, nivel+1, graphC[start][i].second );
            if( retorno > nivel ) {
                res[graphC[start][i].second] = 0;                       
            }
            minimo = min(minimo,retorno);
        }
    }
    
    minLevel[start] = minimo;
    return minimo;
}

int main() {
    ll n, m, s, t, i, a, b, c, result;
    
    cin >> n >> m >> s >> t;
    s--; t--;

    vector< vector<pair<ll,ll> > > graphA(n);
    vector< vector<pair<ll,ll> > > graphB(n);
    graphC.resize(n);
    edges.resize(m);
    vector<ll> pesosA(n,LINF);
    vector<ll> pesosB(n,LINF);
    
    level.resize(n,-1);
    minLevel.resize(n,LINF);

    res.resize(m,-1);

    for( i=0; i<m; i++ ) {
        cin >> edges[i].first >> edges[i].second.first >> edges[i].second.second;
        edges[i].first--;
        edges[i].second.first--;

        graphA[edges[i].first].pb( mp(edges[i].second.second, edges[i].second.first) );
        graphB[edges[i].second.first].pb( mp(edges[i].second.second, edges[i].first) ); 
    } 

    Dijkstra(graphA,s,t,pesosA);
    Dijkstra(graphB,t,s,pesosB);

    for( i=0; i<m; i++ ) {
        if( pesosA[edges[i].first]!=LINF and pesosB[edges[i].second.first]!=LINF and edges[i].second.second+pesosA[edges[i].first]+pesosB[edges[i].second.first] == pesosA[t] ) {
            graphC[edges[i].first].pb( mp(edges[i].second.first,i) );
            graphC[edges[i].second.first].pb( mp(edges[i].first,i) );                    
        }
    } 

    dfs(s,0,-1);

    for( i=0; i<m; i++ ) {
        if( res[i]==0 ) cout << "YES\n";
        else {
            a = pesosA[edges[i].first];
            b = pesosB[edges[i].second.first];
            c = pesosA[t];

            result = ((edges[i].second.second+a+b)-c)+1;
            if( result>=edges[i].second.second ) cout << "NO\n";
            else cout << "CAN " << result << endl;
        }
    }
    return 0;
}
