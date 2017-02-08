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
int n;

vector< set<int> > graph;

int dp( int index, set<int> forbiden ) {
    if( index == n ) return 0;
    if( forbiden.find(index)!=forbiden.end() ) return dp(index+1,forbiden);
    int a, b;
    a = dp(index+1,forbiden);
    //set<int> f2 = forbiden;

    for( set<int>::iterator it=graph[index].begin(); it!=graph[index].end(); ++it ) {
        forbiden.insert(*it);    
    }    
    b = dp(index+1,forbiden);
    return max( a, 1+b );
} 

int main() {
    
    int i, num, teste;
    teste = 1;

    while( sc(n) && n ) {
        graph.clear();
        graph.resize(n);
        
        for( i=0; i<n; i++ ) {
            while( sc(num) && num ) {
                graph[i].insert(num-1);
                graph[num-1].insert(i);
            }
        }
        set<int> aux;
        printf("Teste %d\n", teste++ );
        pri(dp(0,aux));      
        printf("\n");
    }  

	return 0;
}
