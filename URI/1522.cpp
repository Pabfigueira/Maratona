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

vector<int> va;
vector<int> vb;
vector<int> vc;
int tamA;
int tamB;
int tamC;

map< pair<int,pair<int,int> >, int > mapa;
map< pair<int,pair<int,int> >, int >::iterator it;

int solve( int a, int b, int c ) {

//    cout << a << " " << b << " " << c << endl;

    if( a==tamA && b==tamB && c==tamC ) return 1;
    it = mapa.find( mp(a,mp(b,c)) );
    if( it!=mapa.end() ) return it->second;

    if( a<tamA && b<tamB && c<tamC && (va[a]+vb[b]+vc[c])%3==0 ) {
        return mapa[ mp(a,mp(b,c)) ] = solve(a+1,b+1,c+1);
    }

    bool entrou = false;    
    
    if( a<tamA && b<tamB && (va[a]+vb[b])%3==0 ) {
        mapa[ mp(a,mp(b,c)) ] = max(mapa[ mp(a,mp(b,c)) ], solve(a+1,b+1,c) ); 
        entrou = true;
    }
    
    if( a<tamA && c<tamC && (va[a]+vc[c])%3==0 ) {
        mapa[ mp(a,mp(b,c)) ] = max(mapa[ mp(a,mp(b,c)) ], solve(a+1,b,c+1) );
        entrou = true;
    }

    if( b<tamB && c<tamC && (vb[b]+vc[c])%3==0 ) {
        mapa[ mp(a,mp(b,c)) ] = max(mapa[ mp(a,mp(b,c)) ], solve(a,b+1,c+1) );
        entrou = true;
    }
    if( entrou ) return mapa[ mp(a,mp(b,c)) ];
    else return 0;
}


int main() {
    int n, i, na, nb, nc;

    while( sc(n) && n ) { 
        va.clear();
        vb.clear();
        vc.clear();
        mapa.clear();

        for( i=0; i<n; i++ ) {
            sc3(na,nb,nc);
            if( na%3!=0 ) va.pb(na);
            if( nb%3!=0 ) vb.pb(nb);
            if( nc%3!=0 ) vc.pb(nc);
        }
        tamA = va.size();
        tamB = vb.size();
        tamC = vc.size();  

        pri(solve(0,0,0));
        
    }
    return 0;
}
