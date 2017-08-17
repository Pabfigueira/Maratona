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
#define ler freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#define imprime(x, Y)                              \
  for (int X = 0; X < Y; X++) cerr << x[X] << " "; \
  cerr << endl;
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

vector< set<int> > graph;
vector<int> visited;
set<int>::iterator it;

int bfs( int start, int end ) {
    queue< pair<int,int> > fila;

    pair<int,int> atual;
    
    fila.push( mp(start,0) );
    visited[start] = 1;

    while( !fila.empty() ) {
        atual = fila.front();
        fila.pop();

        if( atual.first==end ) return atual.second;

        for( it=graph[atual.first].begin(); it!=graph[atual.first].end(); ++it ) {
            if( visited[*it]==0 ) {
                visited[*it] = 1;
                fila.push( mp(*it,atual.second+1) );
            }    
        }    
    }
    return INF;
}


int main() {
    
    int l, u, r, i, j, next, caso;

    caso = 1;
    vector<int> vetor;

    while( cin >> l >> u >> r and (l||u||r) ) {
        graph.clear();
        graph.resize(10010);

        vetor.clear();
        vetor.resize(r);

        visited.clear();
        visited.resize(10010,0);

        for( i=0; i<r; i++ ) {
            cin >> vetor[i];
        }         

        for( i=0; i<=9999; i++ ) {
            for( j=0; j<r; j++ ) {
                next = (i+vetor[j])%10000;

                graph[i].insert(next);
                //graph[next].insert(i);
            }
        }

        int dist = bfs(l,u);
        cout << "Case " << caso++ << ": ";
        if( dist==INF ) cout << "Permanently Locked\n";
        else cout << dist << endl;
    }

    return 0;
}
