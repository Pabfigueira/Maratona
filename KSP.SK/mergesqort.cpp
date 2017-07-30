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

ll soma, num;
vector<ll> dp;

void solve( ll value ) {
    if( value < 1000000 ) {
        soma += dp[value];
        return;
    }
    ll ant, pos;
    ant = sqrt(value);
    pos = value-ant;
    soma += value;
    solve(ant);
    solve(pos);
}


int main() {
    ll i, ant, pos;

    soma = 0;
    
    scanf("%lld",&num);
    
    dp.resize(1000001,0);

    for( i=2; i<=1000000; i++ ) {
        ant = sqrt(i);
        pos = i-ant;
        dp[i] = i + dp[ant] + dp[pos];             
    }
    
    solve(num);    

    printf("%lld\n",soma);

    return 0;
}
