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

vector<int> vetor;
vector< vector<int> > dp;

int solve( int n, int limite ) {
    if( n==-1 ) return 0;
    
    if( dp[n][limite]!=-1 ) return dp[n][limite];

    if( vetor[n] < limite ) return dp[n][limite] = max(1+solve(n-1,vetor[n]),solve(n-1,limite));

    return dp[n][limite] = solve(n-1,limite);
}

int main() {
    int n, i;

    cin >> n;

    vetor.resize(n);
    dp.resize(n+2,vector<int>(25,-1));
    for( i=0; i<n; i++ ) {
        cin >> vetor[i];
    } 

    cout << solve(n-1,22) << endl; 
    return 0;
}

