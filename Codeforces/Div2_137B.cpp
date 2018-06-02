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
    ll n, m, k, i, j, a, b, aux;
    char op;

    scanf("%lld%lld%lld",&n,&m,&k);

    vector< vector<ll> > matriz(n,vector<ll>(m));

    vector<ll> row(n);
    vector<ll> col(m); 

    for( i=0; i<n; i++ ) {
        row[i] = i;
        for( j=0; j<m; j++ ) {
            if( i==0 ) col[j] = j;
            scanf("%lld",&matriz[i][j]);
        }
    }
    

    for( i=0; i<k; i++ ) {
        scanf("%c%c%lld%lld",&op,&op,&a,&b);
        a--; b--;
        if( op=='c' ) {
            aux = col[a]; 
            col[a] = col[b];
            col[b] = aux;
        } else if( op=='r' ) { 
            aux = row[a];
            row[a] = row[b];
            row[b] = aux;
        } else {
            printf("%lld\n",matriz[row[a]][col[b]]);
        }
    }

    return 0;
}
