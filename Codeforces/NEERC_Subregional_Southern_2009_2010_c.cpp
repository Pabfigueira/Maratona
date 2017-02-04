#include <bits/stdc++.h>

using namespace std;

#define sc(a) scanf("%d", &a)
#define sc2(a, b) scanf("%ld%ld", &a, &b)
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

int n;
long long totalCost;
vector< pair<long int, pair<long int, pair<int, pair<long int, long int> > > > > edges; 
list< pair<long int, pair<long int, pair<int, pair<long int, long int> > > > > inside;
list< pair<long int, pair<long int, pair<int, pair<long int, long int> > > > > outside;
list< pair<long int, pair<long int, pair<int, pair<long int, long int> > > > >:: iterator it; 

map<long int, long int> pai; 

long int Find( long int a ) { return pai[a] == a ? a : pai[a] = Find( pai[a] ); }

void Union( long int a, int b ) { pai[Find(a)] = Find(b); } 


void kruskal() {
    int i;

    for( i=0; i<n; i++ ) {
        if( Find( edges[i].second.second.second.first ) != 
            Find( edges[i].second.second.second.second ) ) {
            
            totalCost -= edges[i].second.first;

            edges[i].second.first *= (-1);
            inside.pb( edges[i] );
            Union(Find(edges[i].second.second.second.first), Find(edges[i].second.second.second.second));
        } else {
            edges[i].second.first *= (-1);
            outside.pb( edges[i] );
        }
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int i;
    long int a, b, c, d;

    totalCost = 0;    

    sc(n);
    edges.resize(n);

    for( i=0; i<n; i++ ) {
        sc2(a,b);
        sc2(c,d);
        edges[i].first = -c;
        edges[i].second.first = -d;
        edges[i].second.second.first = i+1;
        edges[i].second.second.second.first = a;
        edges[i].second.second.second.second = b;
        pai[a] = a;
        pai[b] = b;
    }
    sort(edges.begin(),edges.end());
    kruskal();
    printf("%lld\n",totalCost);
    bool first = true;
    for( it=outside.begin(); it!=outside.end(); ++it ) {
        if( first ) first = false;
        else printf(" ");
        printf("%d",it->second.second.first);
    }

    for( it=inside.begin(); it!=inside.end(); ++it ) {
        if( first ) first = false;
        else printf(" ");
        printf("%d",it->second.second.first);
    }
    printf("\n");
    return 0;
}
