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

int n, camp;
vector<int> vA;
vector<int> vB;

bool solve() {
	int i, j, k, mult;
	bool fail = false;

	for( i=0; i<n; i++ ) {
		mult = camp*vB[i];
		for( j=0; j<n-1 && !fail; j++ ) {
			if( vA[j] * vB[j+1] >= mult ) fail = true;
		}
		if( !fail ) return true;
	}
	return false;
}

int main() {
	BUFF;
	int t, i;
	cin >> t;
	while( t-- ) {
		cin >> n;
		vA.resize(n-1);
		vB.resize(n);
		cin >> camp;
		for( i=0; i<n-1; i++ ) {
			cin >> vA[i];
		}
		for( i=0; i<n; i++ ) {
			cin >> vB[i];
		}
		sort(vA.begin(),vA.end());
		sort(vB.begin(),vB.end());
		reverse(vB.begin(),vB.end());

		if( solve() ) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}
