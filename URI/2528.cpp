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

int bfs( int c, int r, int e ) {
    queue< pair<int,int> > fila;
    pair<int,int> atual;

    vector<int> visited(graph.size(),0);
    
    fila.push( make_pair(c,0) );
    visited[c] = 1;

    while(  !fila.empty() ) {
        atual = fila.front();
        fila.pop();

        if( atual.first==r ) {
            return atual.second;    
        }

        for( int i=0; i<graph[atual.first].size(); i++ ) {
            if( visited[graph[atual.first][i]]==0 and graph[atual.first][i]!=e ) {
                visited[graph[atual.first][i]] = 1;
                fila.push( make_pair(graph[atual.first][i],atual.second+1) );    
            } 
        }
    } 
}

int main() {
	int n,m,i,a,b,c,r,e;

    while( scanf("%d%d",&n,&m) != EOF ) {
        graph.clear();
        graph.resize(n);

        for( i=0; i<m; i++ ) {
            scanf("%d%d",&a,&b);
            a--; b--;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        scanf("%d%d%d",&c,&r,&e);
        c--; r--; e--;
        printf("%d\n",bfs(c,r,e));
    }
	return 0;
}
