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

    int n, m, k, i, j;

    sc3(n,m,k);

    vector<int> vetor(n);

    for( i=0; i<n; i++ ) {
        sc(vetor[i]);
    }
	
    m--;

    i = m-1;
    while( i>=0 && ( vetor[i]==0 || vetor[i]>k ) ) i--;
    j = m+1;
    while( j<n && ( vetor[j]==0 || vetor[j]>k ) ) j++;

    if( i<0 ) cout << (j-m)*10 << endl;
    else if( j>=n ) cout << (m-i)*10 << endl;
    else {
        if( (m-i) > (j-m) ) cout << (j-m)*10 << endl;
        else cout << (m-i)*10 << endl; 
    }
	return 0;
}
