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

vector< vector< vector<int> > > pecas;

void buildPecas() {
    pecas.resize(7);

    vector<int> one(1,4);
    vector<int> two(2);
    vector<int> three(3);
    vector<int> four(4,1);    

    pecas[0].pb(one);
    pecas[0].pb(four);
    
    two[0] = 3;
    two[1] = 1;
    pecas[1].pb(two);
    pecas[2].pb(two);
    two[0] = 1;
    two[1] = 3;
    pecas[1].pb(two);
    pecas[2].pb(two);
    three[0] = 2;
    three[1] = 1;
    three[2] = 1;
    pecas[1].pb(three);
    pecas[2].pb(three);
    three[0] = 1;
    three[1] = 1;
    three[2] = 2;
    pecas[1].pb(three);
    pecas[2].pb(three);

    two[0] = 2;
    two[1] = 2;
    pecas[3].pb(two);

    three[0] = 1;
    three[1] = 2;
    three[2] = 1;
    pecas[4].pb(three);
    pecas[5].pb(three);
    pecas[6].pb(three);
    two[0] = 2;
    two[1] = 2;
    pecas[4].pb(two);
    pecas[6].pb(two);

    two[0]=3;
    two[1]=1;
    pecas[5].pb(two);
    two[0]=1;
    two[1]=3;
    pecas[5].pb(two);

}

int main() {
    BUFF;
    buildPecas();

    int n, m, k, i, j, h, res, trecho;
    char posicao;

    while( cin >> n >> m >> k and n+m+k!=0 ) {

        vector< int > grid(m,0);
        vector< int > minE(m,numeric_limits<int>::max());
        vector< int > minD(m,numeric_limits<int>::max());
    
        for( i=0; i<n; i++ ) {
            for( j=0; j<m; j++ ) {
                cin >> posicao;
                if( posicao=='#' ) grid[j]++;
            }
        }

        for( j=0; j<m; j++ ) {
            if( j>0 ) minE[j] = minE[j-1];
            minE[j] = min(minE[j],grid[j]);    
        }
        for( j=m-1; j>=0; j-- ) {
            if( j<m-1 ) minD[j] = minD[j+1];
            minD[j] = min(minD[j],grid[j]);
        }

        k--;

        res = 0;

        for( i=0; i<pecas[k].size(); i++ ) {
            for( j=0; j<=m-pecas[k][i].size(); j++ ) {
            
                trecho = numeric_limits<int>::max();
            
                for( h=0; h<pecas[k][i].size(); h++ ) {
                    grid[j+h] += pecas[k][i][h];                                 
                    trecho = min(trecho,grid[j+h]);
                }

                if( j>0 )   trecho = min(trecho,minE[j-1]);
                if( h+j<m ) trecho = min(trecho,minD[h+j]);
        
                res = max(trecho,res);             
   
                for( h=0; h<pecas[k][i].size(); h++ ) {
                    grid[j+h] -= pecas[k][i][h];
                } 
            }
        } 
        cout << res << endl;
    }
	return 0;
}
