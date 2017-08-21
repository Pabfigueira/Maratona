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
    ll i, n, m, k, t, num, saved, soma, tirar;

    map<ll,ll> mapa;
    map<ll,ll>::iterator it;

    cin >> n >> m >> k >> t;

    vector<ll> vetor(m);
    
    for( i=0; i<n; i++ ) {
        cin >> num;
        mapa[num-t]++;
    } 
    
    for( i=0; i<m; i++ ) {
        cin >> vetor[i];
    }
    sort(vetor.begin(),vetor.end()); 
    
    saved=0;

    for( i=0; i<m and mapa.size()>0; i++ ) {
        it = mapa.lower_bound(vetor[i]-(2*t));
        if( it!=mapa.end() ) {
            soma = 0;
            while( it!=mapa.end() and soma<k and it->first<=vetor[i] ) {
                tirar = min(k-soma,it->second);
                soma += tirar;
                it->second -= tirar;
                if( it->second==0 ) {
                    mapa.erase(it);
                    it = mapa.lower_bound(vetor[i]-(2*t));
                } else {
                    it++;
                }
            } 
            saved += soma;
        }
    }
    cout << saved << endl;
    return 0;
}
