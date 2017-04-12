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
#define MAX 1000001

ll mySqrt( ll a ) {
    ll raiz;
    raiz = sqrt(a);
    raiz--;
    for( ll i=0; i<3; i++ ) {
        if( raiz*raiz > a ) return raiz-1;
        raiz++;
    }
}

int main() {

    bitset<MAX> bs;
    set<ll> primos;
    int limite;
    
    bs.reset();
    bs.flip();
    
    limite = mySqrt(MAX);

    for( ll i=2; i<=limite; i++ ) {
        if( bs.test((size_t)i)) {
            for( ll j = i*i; j<MAX; j+=i ) {
                bs.set((size_t)j,false);
            }
        }
    }

    for( ll i=2; i<MAX; i++ ) {
        if( bs.test((size_t)i)) { 
            primos.insert(i);
        }
    }

    ll num, n, i, raiz;
    
    scanf("%lld",&n);

    for( i=0; i<n; i++ ) {
        scanf("%lld",&num);
        raiz = mySqrt(num);
        if( raiz*raiz!=num || primos.find( raiz ) == primos.end() ) puts("NO");
        else puts("YES");
    }
    return 0;
}
