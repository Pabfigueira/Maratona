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
#define TAM 2000

int main() {
    int n, i, a, b, c, d, j, somaArea, h, somaPeri;

    vector<vector<int> > field;

    while( sc(n) && n ) { 
        field.clear();
        field.resize(TAM,vector<int>(TAM,0));

        somaArea = 0;
        somaPeri = 0;

        for( h=0; h<n; h++ ) {
            sc2(a,b); sc2(c,d);
            for( i=a; i<a+c; i++ ) {
                for( j=b; j<b+d; j++ ) {
                    if( field[i][j]==0 ) {
                        field[i][j] = 1;
                        somaArea++;
                    }
                }
            } 
        }
        
        for( i=0; i<TAM; i++ ) {
            for( j=0; j<TAM; j++ ) {
                if( field[i][j] == 1 ) {
                    if( i==0 ) somaPeri++;
                    if( j==0 ) somaPeri++;
                    if( j==TAM-1 ) somaPeri++;
                    if( j==TAM-1 ) somaPeri++;
                    if( i>0 && field[i-1][j]==0 ) somaPeri++;
                    if( j>0 && field[i][j-1]==0 ) somaPeri++;
                    if( i<TAM-1 && field[i+1][j]==0 ) somaPeri++;
                    if( j<TAM-1 && field[i][j+1]==0 ) somaPeri++;      
                }
            }
        }
    
        printf("%d %d\n",somaArea,somaPeri);
    
    }	
	return 0;
}
