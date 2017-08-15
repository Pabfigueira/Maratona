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

bool Myfunct( ll num ) {
    bitset<64> bits(num);
    stringstream S;
    S << bits;
    word.clear();
    word = S.str(); 

    while( word[0]=='0' ) word.erase(word.begin());     

    int i, tam=word.size();
    

    for( i=1; i<tam; i++ ) {
        if( word[i]==word[i-1] ) return false;
    }
    return true;
}


int main() {
    ll num;

    cin >> num;

    if( Myfunct(num) ) cout << 1 << endl;
    else cout << -1 << endl;
    
    return 0;
}
