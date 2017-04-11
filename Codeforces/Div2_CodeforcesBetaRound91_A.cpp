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
int n;
bool check;

void divide( int qt, int tam, int atual) {
    if( qt==tam ) {
        if( n%atual == 0 ) check = true;
        return;
    }
    if( atual!=0 && n%atual == 0 ) check = true;
    if( check ) return;
    divide(qt+1,tam,(atual*10)+4);
    divide(qt+1,tam,(atual*10)+7);
}

int main() {
    check = false;
    int tam;

    sc(n);
    
    string word; 
    stringstream S;
    S << n;
    word = S.str();    
	tam = word.size();
    
    divide(0,tam,0);
    if( check ) cout << "YES";
    else cout << "NO";
    cout << endl;

	return 0;
}
