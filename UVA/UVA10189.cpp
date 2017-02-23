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
#define ler freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#define imprime(x, Y)                              \
  for (int X = 0; X < Y; X++) cerr << x[X] << " "; \
  cerr << endl;
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

    int n, m, i, j, cont, novo;

    novo = 1;

    vector< vector<char> > matriz;

    while( sc2(n,m) && (n||m) ) {

        matriz.clear();
        matriz.resize(n, vector<char>(m));

        for( i=0; i<n; i++ ) { 
            for( j=0; j<m; j++ ) {
                cin >> matriz[i][j];
            }
        }
        if( novo != 1 ) printf("\n");
        printf("Field #%d:\n",novo++);
        for( i=0; i<n; i++ ) {
            for( j=0; j<m; j++ ) {
                if( matriz[i][j] == '*' ) 
                    printf("*");
                else {
                    cont = 0;
                    if( i>0 && matriz[i-1][j] == '*' ) cont++;
                    if( i>0 && j>0 && matriz[i-1][j-1] == '*' ) cont++;
                    if( i>0 && j<m-1 && matriz[i-1][j+1] == '*' ) cont++;
                    if( i<n-1 && matriz[i+1][j] == '*' ) cont++;
                    if( i<n-1 && j>0 && matriz[i+1][j-1] == '*' ) cont++;
                    if( i<n-1 && j<m-1 && matriz[i+1][j+1] == '*' ) cont++;
                    if( j>0 && matriz[i][j-1] == '*' ) cont++;
                    if( j<m-1 && matriz[i][j+1] == '*' ) cont++;
                    printf("%c",cont + '0' );
                }
                     
            }
            printf("\n");
        }
        //printf("\n");
    }
    
    return 0;
}
