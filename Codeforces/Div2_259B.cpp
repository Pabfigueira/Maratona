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
    ll n, i, menor, j;
    
    scanf("%lld",&n);

    vector<ll> vetor(n);
    vector<ll> started(n,0);

    for( i=0; i<n; i++ ) {
        scanf("%lld",&vetor[i]);
        if( i==0 ) menor = vetor[i];
        else menor = min(menor,vetor[i]);
    }	

    i = 0;
    while( vetor[i]!=menor ) {
        i++;
    }

    started[i] = 1;

    j = i+1;
    if( j==n ) j=0;

    while( j!=i ) {
        if( j==0 and vetor[n-1] > vetor[j] ) {
            if( vetor[j]==menor and started[j]==0 ) {
                started[j] = 1;
                i = j;
            } else {
                printf("-1\n");
                return 0;
            }
        } else if( j!=0 and vetor[j-1] > vetor[j] ) {
            if( vetor[j]==menor and started[j]==0 ) {
                started[j] = 1;
                i = j;
            } else {
                printf("-1\n");
                return 0;
            }
        }
        j++;
        if( j==n ) j=0;
    }
    if( i==0 ) printf("0\n");
    else printf("%lld\n",n-i);
    
	return 0;
}
