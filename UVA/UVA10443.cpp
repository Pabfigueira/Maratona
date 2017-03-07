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

    int a, teste, n, m, qt, i, j;

    sc(teste);
    
    vector< vector<char> > matriz;
    vector< vector<char> > matriz2;

    for( a=0; a<teste; a++ ) {
        if( a!=0 ) cout << endl;
        sc3(n,m,qt);

        matriz.clear();
        matriz.resize(n,vector<char>(m));

        matriz2.clear();    
        matriz.resize(n,vector<char>(m));

        for( i=0; i<n; i++ ) {
            for( j=0; j<m; j++ ) {
                cin >> matriz[i][j];
            }
        }
        
        while( qt-- ) {
            matriz2 = matriz;
            for( i=0; i<n; i++ ) {
                for( j=0; j<m; j++ ) {
                    if( matriz[i][j] == 'R' ) {

                        if( i>0 ) {
                            if(matriz[i-1][j] == 'S' ) matriz2[i-1][j] = 'R';
                            else if( matriz[i-1][j] == 'P' ) matriz2[i][j] = 'P';
                        }
                        if( j>0 ) { 
                            if( matriz[i][j-1] == 'S' ) matriz2[i][j-1] = 'R';
                            else if( matriz[i][j-1] == 'P' ) matriz2[i][j] = 'P';
                        }     
                        if( i<n-1 ) {
                            if( matriz[i+1][j] == 'S' ) matriz2[i+1][j] = 'R';
                            else if( matriz[i+1][j] == 'P' ) matriz2[i][j] = 'P';
                        }
                        if( j<m-1 ) {
                            if( matriz[i][j+1] == 'S' ) matriz2[i][j+1] = 'R';
                            else if( matriz[i][j+1] == 'P' ) matriz2[i][j] = 'P';
                        }

                    } else if( matriz[i][j] == 'S' ) {
                            
                        if( i>0 ) {
                            if(matriz[i-1][j] == 'R' ) matriz2[i][j] = 'R';
                            else if( matriz[i-1][j] == 'P' ) matriz2[i-1][j] = 'S';
                        }
                        if( j>0 ) { 
                            if( matriz[i][j-1] == 'R' ) matriz2[i][j] = 'R';
                            else if( matriz[i][j-1] == 'P' ) matriz2[i][j-1] = 'S';
                        }     
                        if( i<n-1 ) {
                            if( matriz[i+1][j] == 'R' ) matriz2[i][j] = 'R';
                            else if( matriz[i+1][j] == 'P' ) matriz2[i+1][j] = 'S';
                        }
                        if( j<m-1 ) {
                            if( matriz[i][j+1] == 'R' ) matriz2[i][j] = 'R';
                            else if( matriz[i][j+1] == 'P' ) matriz2[i][j+1] = 'S';
                        }

                    } else {
                        
                        if( i>0 ) {
                            if(matriz[i-1][j] == 'S' ) matriz2[i][j] = 'S';
                            else if( matriz[i-1][j] == 'R' ) matriz2[i-1][j] = 'P';
                        }
                        if( j>0 ) { 
                            if( matriz[i][j-1] == 'S' ) matriz2[i][j] = 'S';
                            else if( matriz[i][j-1] == 'R' ) matriz2[i][j-1] = 'P';
                        }     
                        if( i<n-1 ) {
                            if( matriz[i+1][j] == 'S' ) matriz2[i][j] = 'S';
                            else if( matriz[i+1][j] == 'R' ) matriz2[i+1][j] = 'P';
                        }
                        if( j<m-1 ) {
                            if( matriz[i][j+1] == 'S' ) matriz2[i][j] = 'S';
                            else if( matriz[i][j+1] == 'R' ) matriz2[i][j+1] = 'P';
                        }

                    }
                }
            }
            matriz = matriz2;
        }

        for( i=0; i<n; i++ ) {
            for( j=0; j<m; j++ ) {
                cout << matriz[i][j];
            }
            cout << endl;
        }
    }    
    return 0;
}
