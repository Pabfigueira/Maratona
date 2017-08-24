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
    int num, i, qt, parc;
    string word;
    getline(cin,word);
    map<char,int> mapa;
    map<char,int>::iterator it;

    cin >> num;

    for( i=0; i<word.size(); i++ ) {
        mapa[word[i]]++;
    } 

    qt = 0;

    it = mapa.begin();

    num-=mapa.size();

    while( it!=mapa.end() and num>0 ) {
        if( it->second>0 ) {
            parc = it->second-1;
            qt += min(num,parc);
            num -= min(num,parc);
        }
        it++;
    }
    if( num<=0 ) 
        cout << qt << endl;
    else
        cout << "impossible\n";
	return 0;
}
