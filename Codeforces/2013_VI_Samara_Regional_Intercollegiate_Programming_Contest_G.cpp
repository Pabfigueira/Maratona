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
    BUFF;
    ll k, n, m, i, h, j, minimoOne, maximoZer;
    char letter;
    cin >> k >> n >> m;

    vector< vector<ll> > matriz(n,vector<ll>(m,0));
    vector<ll> resp;
    vector< vector<vector<ll> > > matrizes(k,vector<vector<ll> >(n,vector<ll>(m)));

    for( h=0; h<k; h++ ) {
        for( i=0; i<n; i++ ) {
            for( j=0; j<m; j++ ) {
                cin >> letter;
                matrizes[h][i][j] = letter-'0';
                matriz[i][j]+=matrizes[h][i][j];
            }
        }
    }

    for( h=0; h<k; h++ ) {
        minimoOne = numeric_limits<ll>::max();
        maximoZer = numeric_limits<ll>::min();

        for( i=0; i<n; i++ ) {
            for( j=0; j<m; j++ ) {
                if( matrizes[h][i][j]==1 ) minimoOne = min(minimoOne,matriz[i][j]);
                else maximoZer = max(maximoZer,matriz[i][j]);                
            }
        } 
        if( minimoOne == numeric_limits<ll>::max() ) resp.pb(maximoZer+1);
        else if( maximoZer==numeric_limits<ll>::min() ) resp.pb(minimoOne);
        else if( minimoOne > maximoZer ) resp.pb(minimoOne);  
    }
    if( resp.size() == k ) {

        for( i=0; i<n; i++ ) {
            for(j=0; j<m; j++ ) {
                if( j>0 ) cout << " ";
                cout << matriz[i][j];
            }
            cout << endl;
        }
    
        for( i=0; i<k; i++ ) {
            if( i>0 ) cout << " ";
            cout << resp[i];
        }
        cout << endl;
    } else {
        cout << "IMPOSSIBLE\n";
    }
    return 0;
}
