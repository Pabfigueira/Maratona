#include <bits/stdc++.h>

using namespace std;

#define sc(a) scanf("%d", &a)
#define sc2(a, b) scanf("%d%d", &a, &b)
#define sc3(a, b, c) scanf("%d%d%d", &a, &b, &c)
#define scs(a) scanf("%s", a)
#define mp make_pair
#define pb push_back
#define BUFF ios::sync_with_stdio(false);
#define db(x) cerr << #x << " == " << x << endl
#define dbs(x) cerr << x << endl
#define ler freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#define imprime(x, Y)                              \
  for (ll X = 0; X < Y; X++) cerr << x[X] << " "; \
  cerr << endl;
typedef long long int ll;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef vector<ll> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vector<ii> > vvii;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const ld pi = acos(-1);
const int MOD = 1e9 + 7;

vector< vector< pair<ll,ll> > > graphC;

vector<ll> level;
vector<ll> minLevel;

vector<ll> res;

ll dfs( ll start, ll nivel, ll edgeDad ) {      
    if( level[start]!=-1 ) {
        if( minLevel[start]==LINF ) return level[start];
        return minLevel[start];
    }

    level[start] = nivel;

    ll retorno, minimo = nivel;

    for( ll i=0; i<graphC[start].size(); i++ ) {
        if( graphC[start][i].second!=edgeDad ) {
            retorno = dfs( graphC[start][i].first, nivel+1, graphC[start][i].second );
            if( retorno > nivel ) {
                res[graphC[start][i].second] = 0;                       
            }
            minimo = min(minimo,retorno);
        }
    }
    
    minLevel[start] = minimo;
    return minimo;
}

int main() {
    BUFF;
    ll n, m, i, a, b, contador;

    while( cin >> n >> m ) {
        graphC.clear(); 
        graphC.resize(n);
    
        level.clear();
        minLevel.clear();
        res.clear();

        level.resize(n,-1);
        minLevel.resize(n,LINF);

        res.resize(m,-1);

        for( i=0; i<m; i++ ) {
            cin >> a >> b;
            a--; b--;
            graphC[a].push_back( make_pair(b,i) );
            graphC[b].push_back( make_pair(a,i) );
        }

        dfs(0,0,-1);
    
        contador = 0;
        
        for( i=0; i<m; i++ ) {
            if( res[i]==0 ) contador++;
        }
        cout << contador << endl;
    }
    return 0;
}
