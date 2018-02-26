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

vector< vector<ll> > graph;
vector<ll> visited;

void dfs( ll actual ) {
    visited[actual] = 1;
    for( ll i=0; i<graph[actual].size(); i++ ) {
        if( visited[graph[actual][i]]==0 ) {
            dfs( graph[actual][i] );
        }
    }
}

int main() {
    BUFF;

    ll n, i, cont, j;

    cin >> n; 

    graph.resize(n);
    visited.resize(n,0);
    vector< pair<ll,ll> > vetor(n);

    for( i=0; i<n; i++ ) {
        cin >> vetor[i].first >> vetor[i].second;
    }
    
    for( i=0; i<n; i++ ) {
        for( j=i+1; j<n; j++ ) {
            if( vetor[i].first==vetor[j].first or 
                vetor[i].second==vetor[j].second ) {
                graph[i].push_back(j);
                graph[j].push_back(i);    
            }
        }
    }
    
    cont = 0;

    for( i=0; i<n; i++ ) {
        if( visited[i]==0 ) {
            dfs(i);
            cont++;
        }
    }
    cout << cont-1 << endl;
	return 0;
}
