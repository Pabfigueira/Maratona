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

vector< vector<int> > graphA;
vector< vector<int> > graphB;

vector<int> in;
vector<int> out;

int contador, iout=0, maxOut=0;

void dfs( int node,vector< vector<int> >& graph ) {
    in[node] = contador++;
    for( int i=0; i<graph[node].size(); i++ ) {
        if( in[graph[node][i]]==-1 ) {
            dfs(graph[node][i],graph);
        }
    }
    out[node] = contador++;            
    if( out[node] > maxOut ) {
        out[node] = maxOut;
        iout = node; 
    }
}


void kosa() {
    contador = 1;
    for( int i=0; i<graphA.size(); i++ ) {
        if( in[i]==-1 ) {
            dfs(i,graphA);
        } 
    }
}

bool solve() {
    for( int i=0; i<graphB.size(); i++ ) {
        in[i] = -1;
    } 
    dfs(iout,graphB);
    for( int i=0; i<graphB.size(); i++ ) {
        if( in[i]==-1 ) return false; 
    }
    return true;
}

int main() {
    int n, i,a, b;

    scanf("%d",&n);

    graphA.resize(n);
    graphB.resize(n);
    in.resize(n,-1);
    out.resize(n,-1);

    for( i=0; i<n; i++ ) {
        scanf("%d%d",&a,&b);
        a--; b--;
        graphA[a].push_back(b);
        graphB[b].push_back(a);
    }	

    kosa();
    
    if( solve() ) printf("S\n");
    else printf("N\n");    
	return 0;
}
