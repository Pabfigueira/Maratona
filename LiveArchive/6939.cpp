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

vector< vector<int> > graph;

int people, ocs, QTD, TIME;

//grafo bipartido O(Esqrt(v))
//Para recuperar a resposta, e so colocar um bool
//de false na aresta de retorno e fazer uma bfs/dfs
//andando pelos vertices de capacidade =0 e arestas 
//que nao sao de retorno
struct Edge {
  int v, rev;
  int cap;
  Edge(int v_, int cap_, int rev_) : v(v_), rev(rev_), cap(cap_) {}
};

struct MaxFlow {
  vector<vector<Edge> > g;
  vector<int> level;
  queue<int> q;
  int flow, n;

  MaxFlow(int n_) : g(n_), level(n_), n(n_) {}
  void addEdge(int u, int v, int cap)
  {
    if (u == v) return;
    Edge e(v, cap, int(g[v].size()));
    Edge r(u, 0, int(g[u].size()));
    g[u].push_back(e);
    g[v].push_back(r);
  }

  bool buildLevelGraph(int src, int sink)
  {
    fill(level.begin(), level.end(), -1);
    while (not q.empty()) q.pop();
    level[src] = 0;
    q.push(src);
    while (not q.empty()) {
      int u = q.front();
      q.pop();
      for (auto e = g[u].begin(); e != g[u].end(); ++e) {
        if (not e->cap or level[e->v] != -1) continue;
        level[e->v] = level[u] + 1;
        if (e->v == sink) return true;
        q.push(e->v);
      }
    }
    return false;
  }

  int blockingFlow(int u, int sink, int f)
  {
    if (u == sink or not f) return f;
    int fu = f;
    for (auto e = g[u].begin(); e != g[u].end(); ++e) {
      if (not e->cap or level[e->v] != level[u] + 1) continue;
      int mincap = blockingFlow(e->v, sink, min(fu, e->cap));
      if (mincap) {
        g[e->v][e->rev].cap += mincap;
        e->cap -= mincap;
        fu -= mincap;
      }
    }
    if (f == fu) level[u] = -1;
    return f - fu;
  }

  int maxFlow(int src, int sink)
  {
    flow = 0;
    while (buildLevelGraph(src, sink))
      flow += blockingFlow(src, sink, numeric_limits<int>::max());
    return flow;
  }
};

bool confere( int mid ) {
    MaxFlow g( (2*(people+ocs))+3 );

    for( int i=1; i<=people; i++ ) {
        g.addEdge(0,i,1);
    } 
    
    for( int i=2*(people+1); i<=2*(people+ocs)+1; i++ ) {
        g.addEdge(i,(2*(people+ocs))+2,1);
    }

    for( int i=0; i<people; i++ ) {
        for( int j=0; j<ocs; j++ ) {
            if( graph[i][j]<=mid ) {
                g.addEdge(i+1,2*(people+(j+1)),1);
            }
            if( graph[i][j] + TIME <= mid ) {
                g.addEdge(i+1,2*(people+(j+1))+1,1);
            }
        }
    }
    if( g.maxFlow(0,(2*(people+ocs))+2) >= QTD ) return true;
    return false; 
}

int bb( int e, int d ) {
    int mid = (e + d) / 2;

    if( e==d ) return e;
    
    if(confere(mid)) return bb(e,mid);
    return bb(mid+1,d);  
}



int main() {
    BUFF;
    int t, i, j;

    cin >> t;

    while( t-- ) {
        cin >> people >> ocs >> QTD >> TIME;

        graph.clear();
        graph.resize(people,vector<int>(ocs));
            
        for( i=0; i<people; i++ ) {
            for( j=0; j<ocs; j++ ) {
                cin >> graph[i][j];
            }
        }

        cout << bb(0,10000000) << endl;     
    }
    return 0;
}