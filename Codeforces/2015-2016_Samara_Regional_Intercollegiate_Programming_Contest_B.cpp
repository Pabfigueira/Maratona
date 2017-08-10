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
    int n, m, i, j, cont, maximo;
    char num;
    
    maximo = 0;

    string resp, aux;

    map<string,int> mapa;
    map<string,int>::iterator it;

    cin >> n >> m;

    for( i=0; i<n; i++ ) {
        cont = 0;
        aux = "";
        for( j=0; j<m; j++ ) {
            cin >> num;
            if( num=='1' ) cont++;
            aux += num;
        }
        if( cont>=8 and cont<=15 ) {
            mapa[aux]++;
            maximo = max(maximo,mapa[aux]);
        }
    }
    
    if( mapa.size()==0 ) {
        for( i=0; i<8; i++ ) {
            resp += '1';
        }
        for(;i<m; i++ ) {
            resp += '0';
        }
        cout << resp << endl; 
        return 0;
    }

    for( it=mapa.begin(); it!=mapa.end(); ++it ) {
        if( it->second==maximo ) {
            cout << it->first << endl;
            return 0;
        }
    }
    
    return 0;
}
