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
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n, m, i, j, total, qt;

    sc2(n,m);

    total = qt = 0;
    
    char letter;
    
    int matrix[n][m];

    for( i=0; i<n; i++ ){
        scanf("%c",&letter);
        for( j=0; j<m; j++ ) {
            scanf("%c",&letter);
            matrix[i][j] = letter - '0';
            if( matrix[i][j] != 0 ) qt++;
        }
    }   
    
    total += (2*qt);

    for( i=0; i<n; i++ ) {
        for( j=0; j<m; j++ ) {
            //up 
            if( i==0 ) {
                total += matrix[i][j];
            }
            if( i>0 && matrix[i][j] > matrix[i-1][j]  ) {
                total += matrix[i][j] - matrix[i-1][j];
            }

            //down
            if( i == n-1 ) {
                total += matrix[i][j];
            }
            if( i<n-1 && matrix[i][j] > matrix[i+1][j] ) {
                total += matrix[i][j] - matrix[i+1][j];
            }

            //left
            if( j==0 ){
                total += matrix[i][j];
            }
            if( j>0 && matrix[i][j] > matrix[i][j-1] ) {
                total += matrix[i][j] - matrix[i][j-1];
            }

            //right
            if( j==m-1 ) {
                total += matrix[i][j];
            }
            if( j<m-1 && matrix[i][j] > matrix[i][j+1] ) {
                total += matrix[i][j] - matrix[i][j+1];
            }
        }
    }
    pri(total);

    return 0;
}
