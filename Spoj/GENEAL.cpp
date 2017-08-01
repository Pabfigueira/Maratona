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

map< pair<string,string>, int> saveGrau;
map<string,string> pai;
set<string> people;
set<string>::iterator it, ita;

int grau( string a, string b ) {
    if( a.size()==0 ) return INF;
    if( b.size()==0 ) return INF;
    if( saveGrau.find( mp(a,b) )!=saveGrau.end() ) return saveGrau[ mp(a,b) ];
    if( saveGrau.find( mp(b,a) )!=saveGrau.end() ) return saveGrau[ mp(b,a) ];

    if( a==b ) {
        saveGrau[ mp(a,b) ] = 0;
        return saveGrau[ mp(b,a) ] = 0;
    }
    
    int valor = 1 + min( grau( pai[a], b), grau( a, pai[b]) );

    saveGrau[ mp(a,b) ] = valor;
    return saveGrau[ mp(b,a) ] = valor;
}

int main() {
    BUFF;

    int n, maximo, i, value;
    string one, two, onM, twM;
    
    cin >> n;
    
    for( i=0; i<n; i++ ) {
        cin >> one >> two;
        pai[two] = one;
        people.insert(one);
        people.insert(two);
    }        
    
    maximo = -1;

    for( it=people.begin(); it!=people.end(); ++it ) {
        for( ita=it; ita!=people.end(); ++ita ) {
            value = grau(*it,*ita);
            if( value > maximo ) {
                maximo = value;
                onM = *it;
                twM = *ita;
            }
        }
    }
    if( onM > twM ) swap(onM,twM);
    cout << onM << " " << twM << " " << maximo << endl;
    return 0;
}
