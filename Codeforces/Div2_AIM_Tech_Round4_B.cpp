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

typedef unsigned long long int ll;
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

ll eleva( ll one, ll two ) {
    ll num = 1;
    while( two-- ) {
        num*=one;
    }
    return num;
}

int main() {
    ll n, m, i, j, total, comp;

    scanf("%lld%lld",&n,&m);

    vector<ll> rows(n,0);
    vector<ll> colu(m,0);

    vector< vector<ll> > matriz(n,vector<ll>(m));

    for( i=0; i<n; i++ ) {
        for( j=0; j<m; j++ ) {
            scanf("%lld",&matriz[i][j]);
            rows[i]+=matriz[i][j];
            colu[j]+=matriz[i][j];
        }
    }	

    total = 0;
    
    for( i=0; i<n; i++ ) {
        total += (eleva(2,rows[i])-1) - rows[i];
        comp = m-rows[i];
        total += (eleva(2,comp)-1) - comp;
    } 
    
    for( i=0; i<m; i++ ) {
        total += (eleva(2,colu[i])-1) - colu[i];
        comp = n-colu[i];
        total += (eleva(2,comp)-1) - comp;
    } 

    total += n*m;

    printf("%lld\n",total);
	return 0;
}
