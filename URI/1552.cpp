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

struct point {
    double x;
    double y;
};

vector< int > p;

int Find( int a ) { return p[a] == a ? a : p[a] = Find(p[a]); }

void Union( int a, int b ) { p[Find(a)] = Find(b); }

double dist( point a, point b ) {
    point ponto;
    ponto.x = a.x-b.x;
    ponto.y = a.y-b.y;
    
    return sqrt(ponto.x*ponto.x + ponto.y*ponto.y);
}


int main() {
    
    int c, teste, n, i, j;

    double soma;

    vector< point > vetor;

    vector< pair<double, pair<int,int> > > edges; 

    sc(c);


    for( teste=0; teste<c; teste++ ) {
        sc(n);

        edges.clear();

        p.clear();
        p.resize(n);
        for( i=0; i<n; i++ ) { p[i] = i; }

        vetor.clear();
        vetor.resize(n);
        for( i=0; i<n; i++ ) {
            scanf("%lf %lf",&vetor[i].x, &vetor[i].y);
        }

        for( i=0; i<n; i++ ) {
            for( j=i+1; j<n; j++ ) {
                edges.push_back( mp( dist(vetor[i],vetor[j]),mp(i,j)) );                
            }
        }

        sort(edges.begin(),edges.end());
        soma = 0;
        for( i=0; i<edges.size(); i++ ) {
            if( Find(edges[i].second.first) != Find(edges[i].second.second) ) {
                Union(edges[i].second.first,edges[i].second.second);
                soma += edges[i].first;
            }
        }
        printf("%.2lf\n",soma/100.00);
    }
    return 0;
}
