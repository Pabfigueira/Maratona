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
    ll n, k, first, number, consigo;

    scanf("%lld%lld",&n,&k);

    vector<ll> vetor(n,0);

    number = n;
    first = 0;

    while( k>0 ) {
        if( k>=((n-first)-1) ) {
            vetor[first] = number;
            number--;
            k-=((n-first)-1);    
            first++;
        } else { 
            consigo = ((n-first)-1);
            while( consigo!=k ) {
                first++;
                consigo--;
            }
            vetor[first] = number;
            k=0;
        }
    }  
    for( k=0, number=1; k<n; k++ ) {
        if( k>0 ) printf(" ");
        if( vetor[k]==0 ) printf("%lld",number++);
        else printf("%lld",vetor[k]);    
    }
    printf("\n");
    return 0;
}
