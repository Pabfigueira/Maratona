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

vector< vector<int> > matriz(7,vector<int>(8));

int solve( int i, int j, vector<vector<int> > matriz, set<pair<int,int> >valids ) {
    int x, y, a, b;
    if( i==7 ) return 1;
    if( j==7 ) {
        x = i+1;
        y = 0;
    } else {
        x = i;
        y = j+1;
    }
    if( matriz[i][j]==-1 ) return solve(x,y,matriz,valids);
    
    a = b = 0;
    if( j<=6 && matriz[i][j+1]!=-1 ) {
        int ant, pos;
        pair<int,int> atual;

        ant = matriz[i][j]; 
        pos = matriz[i][j+1];
        atual.first = min(ant,pos);
        atual.second = max(ant,pos);

        if( valids.find( atual )!=valids.end() ) {
            valids.erase(atual); 
            matriz[i][j] = -1;
            matriz[i][j+1] = -1;
            a = solve(x,y,matriz,valids);     
            matriz[i][j] = ant;
            matriz[i][j+1] = pos;
            valids.insert(atual);
        }         
    }   
    if( i<=5 && matriz[i+1][j]!=-1 ) {
        int ant, pos;
        pair<int,int> atual;

        ant = matriz[i][j]; 
        pos = matriz[i+1][j];
        atual.first = min(ant,pos);
        atual.second = max(ant,pos);

        if( valids.find( atual )!=valids.end() ) {
            valids.erase(atual); 
            matriz[i][j] = -1;
            matriz[i+1][j] = -1;
            b = solve(x,y,matriz,valids);     
            matriz[i][j] = ant;
            matriz[i+1][j] = pos;
            valids.insert(atual);
        }              
    } 
    return a+b; 
}

int main() {
    int n, i, j;
    
    sc(n);
    set< pair<int,int> > valids;
    for( i=0; i<7; i++ ) {
        for( j=i; j<7; j++ ) {
            valids.insert( mp(i,j) );
        }
    }

    for( int h=0; h<n; h++ ) {
        for( i=0; i<7; i++ ) {
            for( j=0; j<8; j++ ) {
                sc(matriz[i][j]);
            }
        }
        printf("Teste %d\n",h+1); 
        printf("%d\n\n",solve(0,0,matriz,valids));
    }
    	
	return 0;
}
