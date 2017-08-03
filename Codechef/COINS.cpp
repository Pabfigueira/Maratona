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

vector<ll> vetor(100000001,0);

void solve( ) {
    ll a, b, c, i;
    for( i=0; i<=1e8; i++ ) {
        a = floor(i/2);
        b = floor(i/3);
        c = floor(i/4);
        vetor[i] = max(i,vetor[a]+vetor[b]+vetor[c]);
    }  
}

ll ask(ll num ) {
    if( num<=1e8 ) return vetor[num];
    ll a, b, c;
    a = floor(num/2);
    b = floor(num/3);
    c = floor(num/4);
    return max(num,ask(a)+ask(b)+ask(c));
}

int main() {
    BUFF;
    ll n;
    solve();
    while( cin >> n ) {
        cout << ask(n) << endl;
    }
    return 0;
}
