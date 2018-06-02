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
    ll n, i, s1, s2, a, b;
    bool have;
    scanf("%lld",&n);
    s1 = 0;
    s2 = 0;
    have = false;
    for( i=0; i<n; i++ ) {
        scanf("%lld%lld",&a,&b);
        s1 += a;
        s2 += b;
        if( a%2!=b%2 ) have = true;
    }
    if( s1%2==0 and s2%2==0 ) {
        printf("0\n");
    } else if( s1%2==1 and s2%2==1 and have ) {
        printf("1\n");    
    } else {
        printf("-1\n");
    }
    return 0;
}
