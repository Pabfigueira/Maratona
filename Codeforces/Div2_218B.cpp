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

map< pair<ll,ll>, ll > mapa;
map< pair<ll,ll>, ll >::iterator it;


ll solve( ll one, ll two ) {
    
    if( one == two ) return 0;

    if( two < one ) swap(one,two);
    
    it = mapa.find( mp(one,two) );
    if( it!=mapa.end() ) return it->second;

    if( two%2!=0 and two%3!=0 and two%5!=0 ) return LINF;        
    
    ll aux, best = LINF;

    if( two%5==0 ) {
        aux = solve(one,two/5);
        if( aux!=LINF ) best = min(best,1+aux);
    }
    
    if( two%3==0 ) {
        aux = solve(one,two/3);
        if( aux!=LINF ) best = min(best,1+aux);
    }
    
    if( two%2==0 ) {
        aux = solve(one,two/2);
        if( aux!=LINF ) best = min(best,1+aux);
    }
    
    return mapa[mp(one,two)] = best; 
}

int main() {
    ll a, b, res;

    scanf("%lld%lld",&a,&b);

    res = solve(a,b);

    if( res == LINF ) printf("-1\n");
    else printf("%lld\n",res);	
	
    return 0;
}
