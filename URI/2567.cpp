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

map<string,string> p;
map<string,int> mapa;
map<string,int> maximo;
map<string,int> fixxed;
set<string> used;
map<string,int>::iterator it;

string Find(string a) { return p[a]==a ? a : p[a] = Find(p[a]); }

void Union(string a, string b) { used.insert(a); used.insert(b); p[Find(a)] = Find(b); }

int main() {
    BUFF;

    int n, m, q, i, value;
    string name, name2; 

    cin >> n >> m >> q;

	for( i=0; i<n; i++ ) {
        cin >> name >> value;
        p[name] = name;
        mapa[name] = value;
        fixxed[name] = value;
    }

    for( i=0; i<m; i++ ) {
        cin >> name >> name2;  
        if( Find(name)!=Find(name2) ) {
            Union(name,name2);
        }
    }
    
    for( it=mapa.begin(); it!=mapa.end(); ++it ) {
        name = Find(it->first);
        maximo[name] = max(maximo[name],it->second);             
    }    

    for( i=0; i<q; i++ ) {
        cin >> name;
        value = maximo[Find(name)];
        if( used.find(name)==used.end() ) cout << "S\n";
        else if( value <= 5 ) cout << "S\n";
        else if( fixxed[name] >= 5 ) cout << "S\n";
        else cout << "N\n"; 
    }

	return 0;
}
