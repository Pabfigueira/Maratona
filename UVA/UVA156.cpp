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

map< string, string > mapaW;
map< string, int > mapaC;
map< string, int >::iterator it;
vector< string > words;
vector< string > ananagrams;

void solve() {
    int tam, i, j;
    string aux;
    tam = words.size();
    
    for( i=0; i<tam; i++ ) {
        aux.clear();
        for( j=0; j<words[i].size(); j++ ) {
            aux += tolower(words[i][j]);
        } 
        sort(aux.begin(),aux.end());
        mapaC[aux]++;
        mapaW[aux] = words[i];        
    }
    
    for( it=mapaC.begin(); it!=mapaC.end(); ++it ) {
        if( it->second == 1 )
            ananagrams.push_back( mapaW[it->first] );
    }        
}

int main() {
    
    string word, aux;

    while( getline(cin,word) && word!="#" ) {
        stringstream S;
        S << word;

        while( !S.eof() ) {
            S >> aux;   
            words.push_back(aux);
        }
    }
    solve();
    sort(ananagrams.begin(),ananagrams.end());
    for( int i=0; i<ananagrams.size(); i++ ) {
        cout << ananagrams[i] << endl;
    }
	return 0;
}
