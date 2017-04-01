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

vector<ll> vetor;
vector<ll>:: iterator it; 

void gera( int four, int seven, string word) {
    if( four+seven == 0 ) {
        stringstream S;
        S << word;
        ll number;
        S >> number;
        vetor.push_back(number);    
    } else {
        string a;
        if( four && seven ) {
            a = word;
            a += '4';
            gera(four-1,seven,a);
            word += '7';
            gera(four,seven-1,word);
        } else if( four ) {
            word += '4';
            gera(four-1,seven,word);
        } else if( seven ) {
            word += '7';
            gera(four,seven-1,word);
        }
    }
}

int main() {
    int n, tam, i;
    
    string word;
    stringstream S;

    sc(n);

    S << n; 
    word = S.str();
    tam = word.size();
    if( tam%2!=0 ) tam++;

    word.clear();
    for( i=0; i<tam; i++ ) {
        if( i<tam/2 ) 
            word += '7';
        else
            word += '4';
    }
    stringstream aux;
    aux << word;
    ll numbert;
    aux >> numbert;
    if( n > numbert ) tam+=2; 
    

    gera(tam/2,tam/2, "");

    sort(vetor.begin(),vetor.end());

    it = lower_bound(vetor.begin(),vetor.end(),n);

    printf("%lld\n",*it);

	return 0;
}
