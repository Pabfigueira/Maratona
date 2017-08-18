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
vector<int> color;
int one, two, falta;

void dfs( int root, int cor, int dad ) {
    color[root] = cor;
    if( cor==1 ) one++;
    else two++;

    for( int i=0; i<graph[root].size(); i++ ) {
        if( graph[root][i]!=dad ) {
            if( color[graph[root][i]]==cor ) {
                if( cor==1 ) one--;
                else two--;
                falta++;
                color[root] = 3;
            } else if( color[graph[root][i]]==0 ) {
                if( cor==2 ) dfs(graph[root][i],1,root);
                else dfs(graph[root][i],2,root);
            }
        } 
    }          
}

int main() {
    BUFF;
    int n, m, i, a, b;

    cin >> n >> m;	

    graph.resize(n);

    for( i=0; i<m; i++ ) {
        cin >> a >> b; 
        a--; b--;
        graph[a].pb(b);
        graph[b].pb(a);
    }
    
    color.resize(n,0);
    
    int dif = 0;
    for( i=0; i<n; i++ ) {
        if( color[i]==0 ) {
            one = 0;
            two = 0;
            dfs(i,1,-1);
            dif = abs(dif-abs(one-two));
        }
    }
    cout << dif+falta << endl; 
	return 0;
}
