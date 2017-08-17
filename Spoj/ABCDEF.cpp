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

    ll n, i, j;

    cin >> n;

    vector<ll> vetor(n);
    map<ll,ll> mapa1;
    map<ll,ll> mapa2;
    map<ll,ll> mapaE;
    map<ll,ll> mapaD;
    map<ll,ll>::iterator it,ita;

    for( i=0; i<n; i++ ) {
        cin >> vetor[i];
    }	

    for( i=0; i<n; i++ ) {
        for( j=0; j<n; j++ ) {
            mapa1[vetor[i]*vetor[j]]++;
            mapa2[vetor[i]+vetor[j]]++;
        }
    }

    for( it=mapa1.begin(); it!=mapa1.end(); ++it ) {
        for( i=0; i<n; i++ ) {
            mapaE[it->first+vetor[i]] += it->second;
        }
    }

    for( it=mapa2.begin(); it!=mapa2.end(); ++it ) {
        for( i=0; i<n; i++ ) {
            if(vetor[i]!=0 ) mapaD[it->first*vetor[i]] += it->second;
        }
    }
    ll soma = 0;
    for( it=mapaE.begin(); it!=mapaE.end(); ++it ) {
        ita = mapaD.find(it->first);

        if( ita!=mapaD.end() ) {
            soma += ita->second*it->second;
        } 
    }    
    cout << soma << endl;
	return 0;
}
