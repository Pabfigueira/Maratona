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

int main() {
    ll n, m, i, maximo, a, b, ma, mb; 
    scanf("%lld",&n);	

    vector<ll> one(n);
    vector<ll>::iterator it;

    for( i=0; i<n; i++ ) {
        scanf("%lld",&one[i]);
    }
    sort(one.begin(),one.end());

    scanf("%lld",&m);

    vector<ll> two(m);
    for( i=0; i<m; i++ ) {
        scanf("%lld",&two[i]);
    }
    sort(two.begin(),two.end());
    
    maximo = (n*2) - (m*2);
    ma = n*2;
    mb = m*2;

    for( i=0; i<n; i++ ) {
        a = ((n-i) * 3) + (i*2);
        it = upper_bound(two.begin(),two.end(),one[i]-1);
        b = ((two.end()-it)*3) + ((it-two.begin())*2);
        if( a-b > maximo ) {
            ma = a;
            mb = b;
            maximo = a-b;    
        } else if( a-b == maximo and a > ma ) {
            ma = a;
            mb = b; 
        }
    }     

    printf("%lld:%lld\n",ma,mb);
	return 0;
}
