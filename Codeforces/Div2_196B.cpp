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

int gcd(int x, int y){ return y ? gcd(y,x%y) : abs(x); }

uint64_t lcm( int x, int y ) {
    if(x&&y) return abs(x)/gcd(x,y) * uint64_t(abs(y));
    else return uint64_t(abs(x|y));
}

int main() {
    int a, b, c, d, esq, dir, one, two, mesq, mdir, common;

    cin >> a >> b >> c >> d;

    esq = lcm(a,c);
    one = abs( ((esq/a)*b) - ((esq/c)*d) );
    mesq = max(((esq/a)*b) , ((esq/c)*d) ); 

    
    dir = lcm(b,d);
    two = abs( ((dir/b)*a) - ((dir/d)*c) );
    mdir = max(((dir/b)*a) , ((dir/d)*c) );
       	
    if( a==b and c==d ) { 
        cout << "0/1" << endl;
        return 0;
    }

    common = gcd(one,mesq);
    one/=common; mesq/=common;

    common = gcd(two,mdir);
    two/=common; mdir/=common;

    if( one/(double)mesq <= two/(double)mdir ) cout << one << '/' << mesq << endl;
    else cout << two << '/' << mdir << endl;
    
	return 0;
}
