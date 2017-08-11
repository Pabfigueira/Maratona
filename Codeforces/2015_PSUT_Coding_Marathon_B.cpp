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

int cont;
vector< pair<string,int> > toUse;
vector< set<string> > sons;
set<string> used;
set<string>::iterator it;
set<string> generated;
map<string,int> mapa;

void generate( string word, int index ) {
        
    string copy = word;

    for(int i=0; i<8; i++ ) {
        if( word[i]=='?' ) {
            for( int j=0; j<=9; j++ ) {
                copy[i] = j+'0';
                sons[index].insert(copy);
                generated.insert(copy);
                if( mapa.find(copy)==mapa.end() ) mapa[copy] = cont++;
            }
        }
    }
    
}

bool has( string word ) {
    for( int i=0; i<8; i++ ) {
        if( word[i]=='?' ) return true;
    }
    return false;
}

bool solve( string aux, string word ) {
    for( int i=0; i<8; i++ ) {
        if( word[i]!=aux[i] ) {
            if( aux[i]!='?' ) return false;
        }
    }
    return true;
}

bool inLimite( string word ) {
    stringstream S ;

    S << word;

    int value;

    S >> value;

    if( value < 20110000 or value > 20159999 ) return false;
    return true;
}

int main() {
    BUFF;

    int n, i, j, value, maximo;
    string word, aux; 

    cin >> n >> word;
    
    cont = 1;
    maximo = 0;

    for( i=0; i<n; i++ ) {
        cin >> aux >> value;
        if( aux==word ) {
            cout << value << endl;
            return 0;
        }

        if( has(aux) ) {
            toUse.pb( mp(aux,value) );
        } else {
            used.insert(aux);
        }  
    }
    
    sons.resize(toUse.size());
    
    cont = toUse.size()+1;
    /*for( i=0; i<toUse.size(); i++ ) {
        mapa[toUse[i].first] = cont++;
    }*/

    for( i=0; i<toUse.size(); i++ ) {
        generate(toUse[i].first,i);
    }

    for( i=0; i<toUse.size(); i++ ) {
        if( solve(toUse[i].first,word) ) {
            MaxFlow Dinic(cont+1);
        
            for( j=1; j<=toUse.size(); j++ ) {
                Dinic.addEdge(0,j,1);
            }
        
            for( it=generated.begin(); it!=generated.end(); ++it ) {
                if( used.find(*it)==used.end() and inLimite(*it) ) Dinic.addEdge(mapa[*it],cont,1);
            }

            for( j=0; j<toUse.size(); j++ ) {
                if( j!=i ) {
                    for( it=sons[j].begin(); it!=sons[j].end(); ++it ) {
                        Dinic.addEdge(j+1,mapa[*it],1);
                    }
                } else {
                    Dinic.addEdge(j+1,mapa[word],1);
                }
            }
            if( Dinic.maxFlow(0,cont)==toUse.size() ) maximo = max(maximo,toUse[i].second);
        }
    }

    cout << maximo << endl;

    return 0;
}
