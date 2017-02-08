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
long long  cont;
vector<int> vetor;

vector<int> countInv(int l, int r) {
    vector<int> a,b,c;
    if( l == r ) {
        c.push_back(vetor[l]);
        return c;
    }     
    a = countInv( l, l+((r-l)/2) );
    b = countInv( l+((r-l)/2)+1, r);
    
    int i,j,tamA, tamB;
    tamA = a.size();
    tamB = b.size(); 
    i = j = 0;
    
    while( i<tamA && j<tamB ) {
        c.push_back( min(a[i],b[j]) );
        if( b[j] < a[i] ) { cont+=(tamA-i); j++; } 
        else { i++; }
    }
    while( i<tamA ) { c.push_back(a[i]); i++; }
    while( j<tamB ) { c.push_back(b[j]); j++; }
    return c;
}


int main() {

    int qt, a, i, n;

    sc(qt);

    for( a=0; a<qt; a++ ) {
        sc(n);

        cont = 0;
        vetor.clear();
        vetor.resize(n);

        for( i=0; i<n; i++ ) {
            sc(vetor[i]);
        }
        countInv(0,n-1);
        printf("%lld\n",cont);
    }
	
	return 0;
}
