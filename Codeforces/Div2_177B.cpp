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
    int n, m, d, i, mini, maxi, j, res;

    scanf("%d%d%d",&n,&m,&d);

    vector<int> vetor(n*m);

    scanf("%d",&vetor[0]);
    mini = maxi = vetor[0];

    for( i=1; i<n*m; i++ ) {
        scanf("%d",&vetor[i]);
        mini = min(mini,vetor[i]);
        maxi = max(maxi,vetor[i]);
        if( vetor[i]%d!=vetor[0]%d ) {
            printf("-1\n");
            return 0;
        }
    }

    vector< vector<int> > dp( 2, vector<int>(((maxi-mini)/d)+5,0));

    for( i=1; i<=n*m; i++ ) {
        for( j=mini; j<=maxi; j+=d ) {
            if( i%2==1 ) 
                dp[1][(j-mini)/d] = dp[0][(j-mini)/d] + (abs(j-vetor[i-1]) / d);
            else
                dp[0][(j-mini)/d] = dp[1][(j-mini)/d] + (abs(j-vetor[i-1]) / d);
        }     
    }
    
    res = dp[(n*m)%2][0];
    for( j=mini; j<=maxi; j+=d ) {
        res = min(res,dp[(n*m)%2][(j-mini)/d]);
    }
    printf("%d\n",res);   
	return 0;
}
