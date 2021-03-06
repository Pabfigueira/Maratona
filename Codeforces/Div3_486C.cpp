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
    ll k, a, n, i, sum;

    scanf("%lld",&k);

    vector<ll> vetor;

    vector< pair<ll, pair<ll,ll> > > resp;

    for( a=0; a<k; a++ ) {
        scanf("%lld",&n);
        vetor.clear();
        vetor.resize(n);
        sum = 0;
        for( i=0; i<n; i++ ) {
            scanf("%lld",&vetor[i]);
            sum += vetor[i];
        }
        for( i=0; i<n; i++ ) {
            resp.push_back( mp(sum-vetor[i], mp(a,i) ) );
        }
    }
    sort(resp.begin(),resp.end());
    for( i=1; i<(ll)resp.size(); i++ ) {
        if( resp[i].first == resp[i-1].first and resp[i].second.first!=resp[i-1].second.first ) {
            printf("YES\n");
            printf("%lld %lld\n",resp[i].second.first+1, resp[i].second.second+1);
            printf("%lld %lld\n",resp[i-1].second.first+1, resp[i-1].second.second+1);
            return 0;
        }
    } 	
    printf("NO\n");
	return 0;
}
