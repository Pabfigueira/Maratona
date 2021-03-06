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
    int n, m, i, atual;
    
    long long time;
    
    time = 0;
    atual = 1;

    sc2(n,m);
        
    vector<int> vetor(m);
    
    for( i=0; i<m; i++ ) {
        sc(vetor[i]);
    }	

    i = 0;

    while( i<m ) {
        while( i<m && atual == vetor[i] ) {
            i++;
        }
        if( i<m ) {
            if( atual < vetor[i] ) {
                time += vetor[i] - atual;
                atual = vetor[i];
            } else {
                time += (n-atual) + vetor[i];
                atual = vetor[i];
            }   
        }
        i++;
    }
    cout << time << endl;
	return 0;
}
