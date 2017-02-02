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

vector< vector<int> > graphA;
vector<int> level;

void bfs() {
    int i, tam;
    pair<int,int> atual;
    queue< pair<int,int> > fila;
    fila.push( make_pair(0,1) );
    level[0] = 1;
    
    while( !fila.empty() ) {
        atual = fila.front();
        fila.pop();
        tam = graphA[atual.first].size();
        for( i=0; i<tam; i++ ) {
            if( !level[ graphA[atual.first][i] ] ) {
                level[ graphA[atual.first][i] ] = atual.second+1;
                fila.push( make_pair( graphA[atual.first][i], atual.second+1 ) );
            }         
        }
    }        
} 


bool dfs(int atual) {
    int i, tam;
    tam = graphA[atual].size();
    for( i=0; i<tam; i++ ) {
        if( level[ graphA[atual][i] ] > level[atual] ) {
            if( !dfs( graphA[atual][i] ) ){
                return true;
            }
        }
    }
    return false;              
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int n, m, a, b, i;

    sc2(n,m);
    
    graphA.resize(n);
    level.resize(n,0);

    for( i=0; i<m; i++ ) {
        sc2(a,b);
        a--; b--;
        graphA[a].push_back(b);
        graphA[b].push_back(a);
    }
    
    bfs();    
    if( dfs(0) ){
        printf("Vladimir\n");
    } else {
        printf("Nikolay\n");
    }

    return 0;
}
