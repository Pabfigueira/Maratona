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
    ll n, i;

    cin >> n;

    vector<ll> vetor(n);
    map<ll,vector<ll> > mapa;
    map<ll,vector<ll> >::iterator it;
    
    ll minimo, who;
    minimo = numeric_limits<ll>::max();

    for( i=0; i<n; i++ ) {
        cin >> vetor[i];
        if( vetor[i]==0 ) {
            cout << i+1 << " " << 1 << endl;
            return 0;
        }
        if( i>0 ) vetor[i] += vetor[i-1];
        if( vetor[i]==0 and i+1 < minimo ) {
            minimo = i+1;
            who = 1;    
        }
        mapa[vetor[i]].pb(i+2);
    }
   
    for( it=mapa.begin(); it!=mapa.end(); ++it ) {
        if( it->second.size()>1 ) {
            for( i=1; i<it->second.size(); i++ ) {
                if( it->second[i]-it->second[i-1] < minimo ) {
                    minimo = it->second[i]-it->second[i-1];
                    who = it->second[i-1];
                }                        
            }
        }
    }    
    if( minimo==numeric_limits<ll>::max() ) cout << "-1\n";
    else cout << who << " " << minimo << endl;
    return 0;
}
