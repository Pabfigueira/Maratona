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

vector<ll> vetor;
vector<ll> sum;

map< pair<ll,ll>, ll > mapa;
map< pair<ll,ll>, ll >::iterator ita;

vector< vector<ll> > victory;

ll n, k;

ll solve( ll index, ll falta ) {
    if( index+k-1 > n or falta==0 ) return 0;
    
    ita = mapa.find( mp(index,falta) );
    if( ita!=mapa.end() ) return ita->second;

    ll a, b;
    a = sum[index+k-1]-sum[index-1] + solve(index+k,falta-1);
    b = solve(index+1,falta);
    
    if( a>=b ) {    
        victory[index].clear();
        if( victory[index+k].size() == 1 ) {
            victory[index].push_back(victory[index+k][victory[index+k].size()-1]);
        } else if( victory[index+k].size() > 1 ) {
            ll ant =  victory[index+k][victory[index+k].size()-1]; 
            ll pos =  victory[index+k][victory[index+k].size()-2];
            if( sum[ant + k - 1] - sum[ant-1]  >= 
                sum[pos + k - 1] - sum[pos-1] ) {
                victory[index].push_back(victory[index+k][victory[index+k].size()-1]);
            } else {
                victory[index].push_back(victory[index+k][victory[index+k].size()-2]);
            }
        }
        victory[index].push_back(index);
        return mapa[mp(index,falta)] = a;
    } else {
        victory[index] = victory[index+1];
        return mapa[mp(index,falta)] = b;
    }
}


int main() {
    ll i;

    scanf("%lld %lld",&n,&k);

    vetor.resize(n+2,0);
    sum.resize(n+2,0);
    victory.resize(n+2);

    for( i=1; i<=n; i++ ) {
        scanf("%lld",&vetor[i]);
        sum[i] = sum[i-1]+vetor[i];
    }   
    
    solve(1,2);
    cout << victory[1][victory[1].size()-1] << " " << victory[1][victory[1].size()-2] << endl;
    return 0;
}
