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
    ll v, i, j;
    vector<ll> costs(10);
    scanf("%lld",&v);

    for( i=1; i<=9; i++ ) {
        scanf("%lld",&costs[i]);
    }  	

    vector<ll> dp(v+1,0);
    vector<ll> back(v+1,-1);

    for( i=1; i<=v; i++ ) {
        for( j=9; j>=1; j-- ) {
            if( i>=costs[j] and dp[i-costs[j]]+1 > dp[i] ) {
                dp[i] = dp[i-costs[j]]+1;
                back[i] = j; 
            }                 
        }
    }

    vector<int> vetor;
    i=v;
    while( i>0 and dp[i]==0 ) i--;
    while( i>0 ) {
        if( back[i]==-1 ) break;
        vetor.push_back(back[i]);
        i -= costs[back[i]];
    }

    if( vetor.size()==0 ) printf("-1\n");
    else {
        for( i=0; i<(ll)vetor.size(); i++ ) {
            printf("%lld",vetor[i]);
        }
        printf("\n");
    }
	return 0;
}
