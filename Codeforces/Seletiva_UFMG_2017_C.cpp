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

int position;

vector<int> pre;
vector<int> em;
vector<int> mapa;

void solve( int e, int d ) {
    position++;

    int value, indice;
    value = pre[position];

    indice = mapa[pre[position]];

    if( indice!=e ) solve(e,indice-1);
    
    if( indice!=d ) solve(indice+1,d);

    cout << value+1 << " ";
}

int main() {
    BUFF;
	int n, i;

    cin >> n;

    pre.resize(n);
    em.resize(n);
    mapa.resize(n+5);

    for( i=0; i<n; i++ ) {
        cin >> em[i];
        em[i]--;
        mapa[em[i]] = i;
    }

    for( i=0; i<n; i++ ) {
        cin >> pre[i];
        pre[i]--;
    }

    position = -1;

    solve(0,n-1);
    cout << endl;

    return 0;
}
