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

bool bfs( ll start, ll end ) {
    vector<ll> visited(105,0);

    queue<ll> fila;
    ll topo;

    visited[start] = 1;
    fila.push( start );

    while( !fila.empty() ) {
        topo = fila.front();
        fila.pop();

        if( topo==end ) return true;

        for( ll i=0; i<(ll)graph[topo].size(); i++ ) {
            if( visited[ graph[topo][i] ] == 0  ) {
                visited[ graph[topo][i] ] = 1;
                fila.push( graph[topo][i] );
            }
        } 
    }
    return false;
}

int main() {
    ll n, i, op, start, end, j, index;

    scanf("%lld",&n);

    vector< pair<ll,ll> > intervals;
 
    graph.resize(105);    

    for( i=0; i<n; i++ ) {
        scanf("%lld%lld%lld",&op,&start,&end);
        if( op==1 ) {
            index = intervals.size();
            for( j=0; j<(ll)intervals.size(); j++ ){
                if( (start<intervals[j].first and intervals[j].first<end) or (start<intervals[j].second and intervals[j].second<end) ) {
                    graph[j].push_back(index);                      
                }
                if( (intervals[j].first<start and start<intervals[j].second) or (intervals[j].first<end and end<intervals[j].second) ) {
                    graph[index].push_back(j);                      
                }

            }       
            intervals.push_back( mp(start,end) ); 
        } else {
            start--; end--;
            if( bfs(start,end) ) printf("YES\n");
            else printf("NO\n");
        } 
    }
    return 0;
}
