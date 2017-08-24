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

map<ll,ll> mapa;
vector<ll> ordered;

ll n;

vector< set<ll> > resp;
set<ll>::iterator it;

void solve() {

    ll i, next;

    vector<ll> visited(n,0);
    
    for( i=0; i<n; i++ ) {
        if( visited[i]==0 ) {
            if( mapa[ordered[i]]==i ) {
                visited[i] = 1;
                set<ll> aux;
                aux.insert(i+1);
                resp.pb(aux); 
            } else {
                set<ll> aux;
                aux.insert(i+1);
                visited[i] = 1;
                next = mapa[ordered[i]];
                while( next!=i ) {
                    visited[next] = 1;
                    aux.insert(next+1);
                    next = mapa[ordered[next]]; 
                }
                resp.pb(aux);
            }
        } 
    }
}

int main() {
    ll i;

    scanf("%lld",&n);

    ordered.resize(n);
    
    for( i=0; i<n; i++ ) {
        scanf("%lld",&ordered[i]);
        mapa[ordered[i]] = i;
    }	
    sort(ordered.begin(),ordered.end());

    solve(); 
    printf("%lld\n",resp.size() );
    for( i=0; i<resp.size(); i++ ) { 
        printf("%lld",resp[i].size());
        for(it=resp[i].begin();it!=resp[i].end();++it ) {
            printf(" %lld",*it);
        }
        printf("\n");
    }
	return 0;
}
