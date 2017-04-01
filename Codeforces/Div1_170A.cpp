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

vector<int> p;

int Find( int a ) { return p[a] == a ? a : p[a] = Find(p[a]); }

void Union( int a, int b ) { p[Find(a)] = Find(b); }

int main() {

    int n, m, i, qt, j, h, cont;

    sc2(n,m);

    vector< vector<int> > vetor(n);

    p.resize(m);

    for( i=0;i<m;i++ ) { p[i] = i; }

    for( i=0; i<n; i++ ) {
        sc(qt);
        if(qt) {
            vetor[i].resize(qt);
            for( j=0; j<qt; j++ ) {
                sc(vetor[i][j]);
                vetor[i][j]--;
                for( h=0; h<j; h++ ) {
                    if( Find(vetor[i][h]) != Find(vetor[i][j]) ) {
                        Union(vetor[i][h],vetor[i][j]);
                    }
                }
            }
        }
    }
	
    cont = 0;

    for( i=0; i<n; i++ ) {
        if( vetor[i].size() == 0 ) {
            cont++;
        } else {
            j = 0;
            while( j<i && vetor[j].size()==0 ) {
                j++;
            }
            if( Find(vetor[i][0]) != Find(vetor[j][0]) ) {
                cont++;
                Union(vetor[i][0],vetor[j][0]);
            }
        }
    }
    
    pri(cont);

	return 0;
}
