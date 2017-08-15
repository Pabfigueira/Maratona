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
    ll t, i, num, qt, minimo, parcial, menor;

    vector<ll> dp(1010,LINF);

    dp[0] = 0;
    for( i=1; i<=1008; i++ ) {
        dp[i] = min(dp[i],dp[i-1]+1);
        if( i>1 ) dp[i] = min(dp[i],dp[i-2]+1);
        if( i>4 ) dp[i] = min(dp[i],dp[i-5]+1);    
    }
    
    map<ll,ll> mapa;
    map<ll,ll>::iterator it;

    cin >> t;
    while( t-- ) {
        mapa.clear();

        cin >> qt;  
    
        menor = LINF;

        for( i=0; i<qt; i++ ) {
            cin >> num;
            num+=5;
            menor = min(menor,num);
            mapa[num]++;
        }              
    
        minimo = LINF;
        
        for( i=0; i<=menor; i++ ) {
            parcial = 0;
            for( it=mapa.begin(); it!=mapa.end(); ++it ) {
                parcial += (it->second * dp[ max(i,it->first)-min(i,it->first) ]);
            }
            minimo = min(minimo,parcial);
        } 
        cout << minimo << endl;
    }
	return 0;
}
