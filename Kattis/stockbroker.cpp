#include <bits/stdc++.h>

using namespace std;

#define sc(a) scanf("%lld", &a)
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

ll mini( ll a, ll b ) {
    if( a<=b ) return a;
    return b;
}

int main() {

    ll n, i, pico, vale, money, qt;

    sc(n);

    vector<ll> vetor(n);

    money = 100;

    for( i=0; i<n; i++ ) { sc(vetor[i]); }

    i = 0;

    while( i<n ) {
        vale = vetor[i];
        i++;
        while( i<n && vetor[i]<=vale ) {
            vale = vetor[i];
            i++;
        }
        if( i<n ) {
            pico = vetor[i];
            i++;
            while( i<n && vetor[i]>=pico ) {
                pico = vetor[i];
                i++;
            }
            qt = money/vale;
            qt = mini(qt,100000);
            money -= qt*vale;
            money += qt*pico;
        }
    }    
	printf("%lld\n",money);

	return 0;
}
