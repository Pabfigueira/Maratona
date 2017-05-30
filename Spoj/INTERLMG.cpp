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

vector<ll> p;

ll Find( ll a ) { return p[a] == a ? a : p[a] = Find(p[a]); }

void Union( ll a, ll b ) { p[Find(a)] = Find(b); } 


double mySqrt( double value ) {
    double raiz = sqrt(value);
    raiz -= 2;

    while( raiz*raiz <= value ) {
        raiz++;
    }
    return raiz-1;
}

double dist( double x1, double y1, double x2, double y2 ) {
    return sqrt( (x1-x2)*(x1-x2)  +  (y1-y2)*(y1-y2) );    
}


int main() {
    ll n, i, j;
    vector< pair<double,double> > vetor;
    vector< pair<double, pair<ll,ll> > > edges;
    double maximo;

    while( scanf("%lld",&n) && n ) {
        
        vetor.clear();
        vetor.resize(n);
        p.clear();
        p.resize(n);
        maximo = 0.0;

        for( i=0; i<n; i++ ) {
            p[i] = i;
        }

        edges.clear();

        for( i=0; i<n; i++ ) {
            scanf("%lf%lf",&vetor[i].first,&vetor[i].second);

            for( j=0; j<i; j++ ) {
                edges.pb( mp( dist(vetor[i].first, vetor[i].second, vetor[j].first, vetor[j].second ),mp(i,j)) );    
            }    
        }
        sort(edges.begin(),edges.end());    
        
        for( ll h=0; h<edges.size(); h++ ) {
            if( Find(edges[h].second.first) != Find(edges[h].second.second) ) {
                maximo = max( maximo, edges[h].first ) ;
                Union(edges[h].second.first,edges[h].second.second);
            }
        }
        printf("%.4lf\n",maximo);
    }
    return 0;
}
