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
    ll n, i, util, j, value;
    string word, aux;
    map<char,ll> mapa;
    map<string,ll> vetor;
    map<string,ll>::iterator it;
    cin >> n;
    getline(cin,word);
    
    for( i=0; i<n; i++ ) {
        getline(cin,word);
        mapa.clear();
        aux.clear();
        util = 1;
        
        for( j=0; j<word.size(); j++ ) {
            value = mapa[word[j]];
            if( value==0 ) {
                aux += ('a'+util);
                mapa[word[j]] = util++;
            } else {
                aux += ('a'+value);
            }
        }
        vetor[aux]++;
    }   

    vector<ll> somatorio(1e6+2,0);
    somatorio[1] = 0;
    for( i=2; i<=1e6; i++ ) {
        somatorio[i] = (i-1) + somatorio[i-1];
    }

    ll cont = 0;
    for( it=vetor.begin(); it!=vetor.end(); ++it ) {
        cont += somatorio[it->second];
    }         
    cout << cont << endl;
    return 0;
}
