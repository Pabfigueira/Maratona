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
vector<int> ages;
vector<int> NodePeople;
vector<int> PeopleNode;

int dfs( int start, vector<int>& visited, int node, int minimo ) {
    visited[node] = 1;

    if( node!=start ) minimo = min(minimo,ages[NodePeople[node]]);

    for( int i=0; i<graph[node].size(); i++ ) {
        if( visited[graph[node][i]]==0 ) {
            minimo = min(minimo,dfs(start,visited,graph[node][i],minimo));
        }
    }

    return minimo;
}

int main() {
    int n, m, q, i, a, b, result;
    char op;

    while( scanf("%d%d%d",&n,&m,&q) != EOF ) {
        graph.clear();
        ages.clear();
        NodePeople.clear();
        PeopleNode.clear();
        graph.resize(n);
        ages.resize(n);
        NodePeople.resize(n);
        PeopleNode.resize(n);

        for( i=0; i<n; i++ ) {
            scanf("%d",&ages[i]);
            NodePeople[i] = i;
            PeopleNode[i] = i;
        }

        for( i=0; i<m; i++ ) {
            scanf("%d%d",&a,&b); 
            a--; b--;
            graph[b].pb(a);
        }  
        
        for( i=0; i<q; i++ ) {
            scanf("%c%c%d",&op,&op,&a); 
            a--;
            if( op=='T' ) {
                scanf("%d",&b);
                b--;
                swap(PeopleNode[a],PeopleNode[b]);
                NodePeople[PeopleNode[a]] = a;
                NodePeople[PeopleNode[b]] = b;  
            } else {
                vector<int> visited(n,0);
                result = dfs(PeopleNode[a],visited,PeopleNode[a],INF);
                if( result==INF ) printf("*\n");
                else printf("%d\n",result);
            }
        }
    }	
	return 0;
}
