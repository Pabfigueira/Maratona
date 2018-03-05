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
    ll n, d, i, dist, res;

    scanf("%lld%lld",&n,&d);

    vector<ll> soma(n+2,0);
    vector<ll> vetor(n);
    vector<ll>::iterator it;

    res = 0;

    for( i=1; i<=n; i++ ) {
        soma[i] = soma[i-1]+i;
    } 
    	
    for( i=0; i<n; i++ ) {
        scanf("%lld",&vetor[i]);
    }

    for( i=0; i<n; i++ ) {
        it = upper_bound(vetor.begin(),vetor.end(),vetor[i]+d);
        it--;
        dist = (distance(vetor.begin(),it) - i) - 1;
        if( dist>0 ) res += soma[dist];
    }
    printf("%lld\n",res);
	return 0;
}
