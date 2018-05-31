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

vector<ll> type;
vector< vector<ll> > graph;

vector< vector<ll> > dist;

ll n, m, s, k;

void bfs( ll raiz ) {
    
    ll i;
    pair<ll,ll> topo;

    dist[raiz].resize(n,LINF); 
    vector<ll> visited(n,0);

    queue< pair<ll,ll> > fila;

    for( i=0; i<n; i++ ) {
        if( type[i]==raiz ) {
            visited[i] = 1;
            dist[raiz][i] = 0;
            fila.push( make_pair(0,i) );  
        }
    }     

    while( !fila.empty() ) {
        topo = fila.front();
        fila.pop();

        for( i=0; i<(ll)graph[topo.second].size(); i++ ) {
            if( visited[ graph[topo.second][i] ]==0 ){
                visited[ graph[topo.second][i] ] = 1;
                dist[raiz][ graph[topo.second][i] ] = topo.first + 1;
                fila.push( make_pair(topo.first+1, graph[topo.second][i]) );  
            }
        } 
    }
}


int main() {
    BUFF;

    ll  i, a, b, j, soma;

    cin >> n >> m >> s >> k;
    
    type.resize(n);
    graph.resize(n);
    dist.resize(s);

    for( i=0; i<n; i++ ) {
        cin >> type[i];
        type[i]--;
    }

    for( i=0; i<m; i++ ) {
        cin >> a >> b;
        a--; b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for( i=0; i<s; i++ ) {
        bfs(i);
    } 

    vector<ll> resp(s);

    for( i=0; i<n; i++ ) {
        for( j=0; j<s; j++ ) {
            resp[j] = dist[j][i]; 
        }        
        sort(resp.begin(),resp.end());
        soma = 0;
        for( j=0; j<k; j++ ) {
            soma += resp[j]; 
        }
        if( i>0 ) cout << " ";
        cout << soma;
    }
    cout << endl;
    return 0;
}
