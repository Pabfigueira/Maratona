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

map<ll,ll> dp[101][2];
map<int,ll> dp2[101][2];
string word;

ll solve( ll pos, int start, ll num ) {
    
    if( dp[pos][start].find(num)!=dp[pos][start].end() ) return dp[pos][start][num];

    if( pos==0 ) {
        if( start && num==1 ) return dp[pos][start][num] = 1;
        return dp[pos][start][num] = 0;
    }
    ll soma = 0;
    if( !start ) soma = (soma + solve(pos-1,0,num))%MOD;
    for(int i=1; i<=9; i++ ) {
        if( num%i == 0 ) {
            soma = (soma + solve(pos-1,1,num/i))%MOD;     
        }
    }            
    return dp[pos][start][num] = soma;
}

ll solveZ ( ll pos, int start, int foi ) {
    if( dp2[pos][start].find(foi)!=dp2[pos][start].end() ) return dp2[pos][start][foi];

    if( pos==0 ) {
        if( !start || foi ) return dp2[pos][start][foi] = 1;
        return dp2[pos][start][foi] = 0;
    }

    ll soma = 0;
    for(int i=0; i<=9; i++ ) {
        if( !start && i==0 ) 
            soma = (soma + solveZ(pos-1,0,0))%MOD; 
        else
            soma = (soma + solveZ( pos-1, 1, (foi | (i==0))) )%MOD;     
    }            
    return dp2[pos][start][foi] = soma;     
}



int main() {
    BUFF;

    ll n, num;

    cin >> n;
    
    while( n-- ) {
        cin >> num;
        if( num == 0 )
            cout << solveZ(100,0,0) % MOD << endl;
        else
            cout << solve(100, 0, num) % MOD << endl;
    }     
    return 0;
}
