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

int main() {
    bitset<MAX> bs;
    vector<int> primos;
    vector<int>::iterator it;
    int limite;

    bs.reset();
    bs.flip();

    limite = (int)sqrt(MAX);

    for( int i=2; i<=limite; i++ ) {
        if( bs.test((size_t)i)) {
            for( int j=i*i; j<MAX; j+=i ) {
                bs.set((size_t)j,false);
            }
        }
    }

    for( int i=2; i<MAX; i++ ) {
        if(bs.test((size_t)i)){
            primos.push_back(i);
        }
    }

    int n, m, i, j, num, menor, soma;
 
    cin >> n >> m;

    menor = INF;

    vector< vector<int> > matriz(n,vector<int>(m));

    for( i=0; i<n; i++ ) {
        for( j=0; j<m; j++ ) {
            cin >> num;
            it = lower_bound(primos.begin(),primos.end(),num);
            matriz[i][j] = *it - num;
        }
    }
        
    for( i=0; i<n; i++ ) {
        soma = 0;
        for( j=0; j<m; j++ ) {
            soma += matriz[i][j];
        }
        menor = min(menor,soma);
    }

    for( j=0; j<m; j++ ) {
        soma = 0;
        for( i=0; i<n; i++ ) {
            soma += matriz[i][j];
        }
        menor = min(menor,soma);
    }
    cout << menor << endl;
    
	return 0;
}
