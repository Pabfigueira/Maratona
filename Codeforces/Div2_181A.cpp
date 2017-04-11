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
    int n, num;
    set<int> neg;
    set<int> pos;
    set<int>::iterator it;
    cin >> n;
    for( int i=0; i<n; i++ ) {
        cin >> num;
        if( num < 0 ) neg.insert(num);
        if( num > 0 ) pos.insert(num);    
    }
    cout << 1 << " " << *neg.begin() << endl;
    if( neg.size()%2==0 ) 
        cout << pos.size() + neg.size() - 2;
    else
        cout << pos.size() + neg.size() - 1;

    it = neg.begin();
    it++;
    if( neg.size()%2==0 ) {
        it++;
    }
    while( it!=neg.end() ) {
        cout << " " << *it;
        ++it;
    }
    it = pos.begin();
    while( it!=pos.end() ) {
        cout << " " << *it;
        ++it;
    }
    cout << endl;
    if( neg.size()%2==0 ) {
        it = neg.begin();
        it++;
        cout << "2 0 " << *it << endl;
    } else {
        cout << "1 0\n";
	}
    return 0;
}
