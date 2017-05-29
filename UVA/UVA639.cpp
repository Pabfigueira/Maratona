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

int n, res;

vector< vector< char > > matriz;
set< pair<int,int> > valids;

void solve( vector< vector<char> > matriz, set< pair<int,int> > valids, int cont) {
    if( valids.size()==0 ) {
        res = max(res,cont);
        return;
    } 
    for( set<pair<int,int> >::iterator it=valids.begin(); it!=valids.end(); ++it ) {
        set<pair<int,int> > newValids;
        newValids = valids;


        matriz[it->first][it->second] = '*';
        newValids.erase(*it);
        int i, j;

        i = it->first; i++;
        j = it->second;
        while( i<n && matriz[i][j]!='X' ) {
            newValids.erase( mp(i,j) );
            i++;
        }

        i = it->first; i--;
        j = it->second;
        while( i>=0 && matriz[i][j]!='X' ) {
            newValids.erase( mp(i,j) );
            i--;
        }

        i = it->first;
        j = it->second; j++;
        while( j<n && matriz[i][j]!='X' ) {
            newValids.erase( mp(i,j) );
            j++;
        }
        
        i = it->first; 
        j = it->second; j--;
        while( j>=0 && matriz[i][j]!='X' ) {
            newValids.erase( mp(i,j) );
            j--;
        }

        solve(matriz,newValids,cont+1);    

        matriz[it->first][it->second] = '.';
    }
}


int main() {
    BUFF;
    int i, j;
    while( cin >> n && n ) {
        res = 0;
        matriz.clear();
        matriz.resize(n,vector<char>(n));
        valids.clear();
        
        for( i=0; i<n; i++ ) {
            for( j=0; j<n; j++ ) {
                cin >> matriz[i][j];
                if( matriz[i][j]=='.' ) valids.insert(mp(i,j));
            }
        }
        solve(matriz,valids,0);
        cout << res << endl;
    }
    	
	return 0;
}
