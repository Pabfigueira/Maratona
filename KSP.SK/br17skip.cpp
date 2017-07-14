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
    BUFF;
    ll n, i, soma, ant;
    cin >> n;

    vector<ll> vetor(n);
    vector< pair<ll,ll> > dp;

    for( i=0; i<n; i++ ) {
        cin >> vetor[i];     
    }
    
    ant = vetor[n-1];
    dp.pb( mp(vetor[n-1],n) );
    for( i=n-2; i>=0; i-- ) {
        if( vetor[i]<ant ) {
            dp.pb( mp(vetor[i],i+1) );
            ant = vetor[i];
        }    
    }
    dp.pb( mp(0,0) );
    reverse(dp.begin(),dp.end());
    soma = 0;
    for( i=1; i<dp.size(); i++ ) {
        //cout << dp[i].second << " ";
        //cout << dp[i].first << endl;
        soma += abs(dp[i].second-dp[i-1].second) * dp[i].first;
    }
    cout << soma << endl;
    return 0;
}
