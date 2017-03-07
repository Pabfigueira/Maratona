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

vector< vector<int> > matriz(5, vector<int>(5));

bool check() {
    if( matriz[0][0] + matriz[1][1] + matriz[2][2] + matriz[3][3] + matriz[4][4] == 0 ) return true;
    if( matriz[0][4] + matriz[1][3] + matriz[2][2] + matriz[3][1] + matriz[4][0] == 0 ) return true;
    for( int i=0; i<5; i++ ) {
        if( matriz[i][0] + matriz[i][1] + matriz[i][2] + matriz[i][3] + matriz[i][4] == 0 ) return true;
        if( matriz[0][i] + matriz[1][i] + matriz[2][i] + matriz[3][i] + matriz[4][i] == 0 ) return true;
    }
    return false; 
}

int main() {

    int n, a, match, i, j;
    bool finished;
    vector< pair<int,int> > vetor;

    sc(n);

    for( a=0; a<n; a++ ) {
        finished = false;
        match = 0;
        vetor.clear();
        vetor.resize(76,make_pair(-1,-1));

        for( i=0; i<5; i++ ) {
            for( j=0; j<5; j++ ) {
                if( i==2 && j==2 ) {
                    matriz[i][j] = 0;    
                } else {
                    sc(matriz[i][j]);
                    vetor[ matriz[i][j] ] = make_pair(i,j);
                }
            }
        }

        for( i=0; i<75; i++ ) {
            sc(j);
        
            if( !finished ) {
                if( vetor[j].first != -1 ) {
                    matriz[vetor[j].first][vetor[j].second] = 0; 
                    if( check() ) finished = true;
                }
                match++;                            
            }
        }       
        cout << "BINGO after " << match << " numbers announced\n";             
    }
    return 0;
}
