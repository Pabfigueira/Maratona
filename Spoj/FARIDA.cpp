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
    int n, teste, qt, i;

    vector<ll> dp;
    vector<ll> vetor;

    sc(n);

    for( teste=1; teste<=n; teste++ ) {
        sc(qt);

        if( qt==0 ) 
            printf("Case %d: 0\n", teste);
        else {

            dp.clear();
            vetor.clear();
            vetor.resize(qt+1,0);
            dp.resize(qt+1,0);
            for( i=1; i<=qt; i++ ) {
                scanf("%lld",&vetor[i]);
                if( i==1 ) dp[i] = vetor[i];
                else dp[i] = max(vetor[i]+dp[i-2],dp[i-1]);    
            } 
            printf("Case %d: %lld\n",teste,dp[qt]);   
        }
    }
    return 0;
}
