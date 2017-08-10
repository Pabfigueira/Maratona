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
    int n, m, i, j, cont;

    cin >> n >> m;

    vector< vector<char> > matriz(n,vector<char>(m));
    vector< vector<int> > repV(n,vector<int>(m,0));
    vector< vector<int> > repH(n,vector<int>(m,0));
    
    vector<int> mapaV(max(n,m)+1,0);
    vector<int> mapaH(max(n,m)+1,0);

    for( i=0; i<n; i++ ) {
        for( j=0; j<m; j++ ) {
            cin >> matriz[i][j];
        }
    }

    for( i=0; i<n; i++ ) {
        cont = 1;
        for( j=0; j<m; j++ ) {
            if( matriz[i][j]=='.' ) {
                repH[i][j] = cont++;
                if( repH[i][j]>=max(n,m) ) {
                    mapaH[max(n,m)]++;
                } else {
                    mapaH[repH[i][j]]++;
                }
            } else {
                cont = 1;
            }
        }
    }

    for( j=0; j<m; j++ ) {
        cont = 1;
        for( i=0; i<n; i++ ) {
            if( matriz[i][j]=='.' ) {
                repV[i][j] = cont++;
                if( repV[i][j]>=max(n,m) ) {
                    mapaV[max(n,m)]++;
                } else {
                    mapaV[repV[i][j]]++;
                }

            } else {
                cont = 1;
            }
        }
    }

    for( i=max(n,m)-1; i>=1; i-- ) {
        mapaH[i] += mapaH[i+1];
        mapaV[i] += mapaV[i+1];
    } 
   
    cout << mapaH[1];
    for( i=2; i<=max(n,m); i++ ) {
        cout << " " << mapaH[i]+mapaV[i];
    }
    cout << endl;
    return 0;
}
