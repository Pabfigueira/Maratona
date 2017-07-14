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

    ll n, i, d, a, b, c, j, k;
    
    cin >> n >> d; 

    vector< vector<pair<ll,pair<ll,ll> > > > vetor(d);
    vector< ll > util;
    vector< ll >::iterator it;

    for( i=0; i<n; i++ ) {
        cin >> a >> b >> c;
        vetor[c-1].pb( mp(a,mp(b,i+1) ) );
    }
    for( i=0; i<d; i++ ) {  
        util.clear();
        sort(vetor[i].begin(),vetor[i].end());
        for( j=0; j<vetor[i].size(); j++ ) {
            util.pb( vetor[i][j].first );    
        }
        bool deu = false;
        for( j=0; j<vetor[i].size() && !deu; j++ ) {
            it = upper_bound(util.begin(),util.end(),vetor[i][j].second.first);
            if( it!=util.end() ) {
                deu = true;
                k = 0;
                while( vetor[i][k].first != *it ) {
                    k++;
                }
                cout << "ANO " << vetor[i][j].second.second << " " << vetor[i][k].second.second << endl;
            }
        }
        if( !deu ) cout << "NIE\n";    
    }
    return 0;
}
