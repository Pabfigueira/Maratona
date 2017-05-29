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

ld velocidade, k1, k2;

ld calc( ld teta ) {
    ld x , y;

    x = ( velocidade*velocidade*sin(2.0*teta) ) / 10.00;
    y = ( velocidade*velocidade*sin(teta)*sin(teta) ) / 20.00;

    return (k1*x) + (k2*y);
}

pair<ld,ld> bb ( ld e, ld d ) {
    if( d-e < 1e-9 ) return mp(e,calc(e));
    ld M = (e+d)/2.00;
    

    if( calc(e) > calc(d) ) return bb(e,M);
    return bb(M,d); 
}

int main() {
    int t;
    cin >> t;

    while( t-- ) {
        cin >> velocidade >> k1 >> k2;
        pair<ld,ld> res;
        res = bb(0,pi/2.00);
        cout << setprecision(3) << fixed;
        cout << res.first << " " << res.second << endl;
    }
    return 0;
}
