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

#define NINF numeric_limits<long double>::min()

ll n;
vector< vector< pair<ll,long double> > > g;

long double Dijkstra(ll start, ll end ) {
    
    ll i, tam;
    priority_queue< pair<long double, ll> > toVisit;
    vector<ll> visited;
    vector<long double> cost;
    pair<long double,ll > atual; 
    pair<ll,long double> next; 
    
    visited.resize( g.size(), 0);
    cost.resize( g.size(), NINF);

    atual.first = 100;
    atual.second = start;

    visited[atual.second] = 1;

    toVisit.push(atual);

    while( !toVisit.empty() ) {
        
        atual = toVisit.top();
        toVisit.pop();

        visited[atual.second] = 1;

        if( atual.second == end ) break;

        tam = g[atual.second].size();

        for( i=0; i<tam; i++ ) {
            next = g[atual.second][i];

            if( visited[next.first] == 0 ) {
                if( cost[next.first] < (atual.first * next.second) ) {
                    cost[next.first] = atual.first * next.second;

                    toVisit.push( make_pair(cost[next.first], next.first) );
                }
            }  
        }
    
    } 
    return cost[end];
}

int main() {

    ll m, a, b, i;

    long double p;

    while( scanf("%lld",&n) && n ) {
        g.clear();
        g.resize(n);

        scanf("%lld",&m);

        for( i=0; i<m; i++ ) {
            scanf("%lld %lld %Lf",&a,&b,&p);
            a--; b--;

            p /= 100.00;

            g[a].push_back( mp(b,p) );
            g[b].push_back( mp(a,p) );
        }

        printf("%.7Lf percent\n", Dijkstra(0,n-1) );
    }
    
    return 0;
}
