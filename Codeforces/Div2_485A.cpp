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

    ll n, i;
    cin >> n;
    string word;
    
    set<string> group;
    set<string>::iterator it;
    group.insert("Power");
    group.insert("Time");
    group.insert("Space");
    group.insert("Soul");
    group.insert("Reality");
    group.insert("Mind");

    for( i=0; i<n; i++ ) {
        cin >> word;
        if( word=="purple" ) group.erase("Power");
        if( word=="green" ) group.erase("Time");
        if( word=="blue" ) group.erase("Space");
        if( word=="orange") group.erase("Soul");
        if( word=="red" ) group.erase("Reality");
        if( word=="yellow" ) group.erase("Mind");
    }
    cout << group.size() << endl;
    for( it=group.begin(); it!=group.end(); ++it ) {
        cout << *it << endl;
    }
    return 0;
}
