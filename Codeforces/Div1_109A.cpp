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

string word;
map<char,char> mapa;

int solve( string aux ) {
    int cont1, cont2;
    cont1 = 1; 
    cont2 = 0;
    for( int i=1; i<aux.size(); i++ ) {
        if( aux[i]==aux[0] ) cont1++;
        else cont2++;
    }
    return min(cont1,cont2);
}


int main() {
    int i, k,resp;
    char a, b;
    string aux; 
    resp = 0;

    BUFF;
    getline(cin,word);
    
    cin >> k;

    for( i=0; i<k; i++ ) {
        cin >> a >> b;
        mapa[a] = b;
        mapa[b] = a;        
    }

    i=0;
    while( i<word.size() ) {
        aux.clear();
        aux += word[i];
        i++;
        while( i<word.size() and (mapa[word[i]]==aux[aux.size()-1] or word[i]==aux[aux.size()-1] ) ) {
            aux += word[i];
            i++;
        }
        if( aux.size()>1 ) 
            resp += solve(aux);
        if( i<word.size() and aux.size()>1 ) i--;
    }
    cout << resp << endl;
	return 0;
}
