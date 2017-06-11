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
#define MAX 1e11

vector< pair<ll,ll> > vetor;
vector< vector<ll> > mapa;

ll min( ll a, ll b ) {
    if( a<b ) return a;
    return b;
}


ll solve( ll k, ll l ) {
    if( mapa[k][l]!=-1 ) return mapa[k][l];

    ll minimo = MAX;
    ll resp;

    if( k==0 ) return mapa[k][l] = MAX;

    if( l==1 ) {
        return mapa[k][l] = k*(-vetor[k-1].second);
    }
    
    for( ll i=0; i<k; i++ ) {
        resp = solve(i,l-1);
        if( resp!=MAX){
            minimo = min(minimo, resp + ((k-i)*(-vetor[k-1].second)) ); 
        }
    }
    return mapa[k][l] = minimo;
}


int main() {
    ll k, l, i;

    while( scanf("%lld%lld",&k,&l) && (k||l) ) {
        mapa.clear();
        mapa.resize(k+1,vector<ll>(l+1,-1));
        vetor.clear();
        vetor.resize(k);

        for( i=0; i<k; i++ ) {
            scanf("%lld%lld",&vetor[i].first, &vetor[i].second);
            vetor[i].second*=-1;
        }
        
        sort(vetor.begin(),vetor.end());
        
        printf("%lld\n",solve(k,l));
        
    }
    
    return 0;
}
