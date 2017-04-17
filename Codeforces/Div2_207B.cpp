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

vector<int> color;
vector< vector<int> > graph;

void paint( int init ) {
    
    bool white, red, blue;

    int atual, i;
    queue<int> fila;

    fila.push(init);
    
    while( !fila.empty() ) {
        atual = fila.front();
        fila.pop();

        while( color[atual]!=0 ) {
            if( fila.empty() ) return;
            atual=fila.front();
            fila.pop();
        }
        white = red = blue = true;

        for( i=0; i<graph[atual].size(); i++ ) {
            if( color[graph[atual][i]] == 0 ) fila.push(graph[atual][i]);
            else if( color[graph[atual][i]] == 1 ) white = false;
            else if( color[graph[atual][i]] == 2 ) red = false;
            else if( color[graph[atual][i]] == 3 ) blue = false;
        }
        if( white ) color[atual] = 1;
        else if( red ) color[atual] = 2;
        else if( blue ) color[atual] = 3;
    }      
}


int main() {
    int n, m, a, b, c, i;

    sc2(n,m);

    color.resize(n,0);
    graph.resize(n);
    
    for( i=0; i<m; i++ ) {
        sc3(a,b,c);
        a--; b--; c--;
        graph[a].push_back(b);
        graph[a].push_back(c);
        graph[b].push_back(a);
        graph[b].push_back(c);
        graph[c].push_back(a);
        graph[c].push_back(b);    
    }	
    
    for( i=0; i<n; i++ ) {
        if( color[i]==0 ) 
            paint(i);
    }

    printf("%d",color[0]);
    for( i=1; i<n; i++ ) {
        printf(" %d",color[i]);
    }
    printf("\n");
	return 0;
}
