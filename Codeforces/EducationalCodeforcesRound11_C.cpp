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
    int n, m, zero, i, maximo, j, ant, pos;

    sc2(n,m);
    
    vector<int> vetor(n);

    zero = maximo = 0;

    for( i=0; i<n; i++ ) {
        sc(vetor[i]);
    }

    i = j = ant = pos = 0;

    while( i<n && j<n ) {
        while( j<n && (vetor[j]==1 || zero<m) ) {
            if( vetor[j]==0 ) zero++;
            j++;
        }
        if( j-i > maximo ) {
            maximo = j-i;
            ant = i;
            pos = j;
        }
        while( i<n && zero==m ) {
            if( vetor[i]==0 ) zero--;
            i++;
        }
    }
    pri(maximo);
    for( i=0; i<n; i++ ) {
        if( i!=0 ) printf(" ");
        if( i>=ant && i<pos ) printf("1");
        else printf("%d",vetor[i]);
    }
    printf("\n");
    return 0;
}
