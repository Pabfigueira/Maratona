#include <bits/stdc++.h>

using namespace std;

#define sc(a) scanf("%d", &a)
#define sc2(a, b) scanf("%lld%lld", &a, &b)
#define sc3(a, b, c) scanf("%lld%lld%lld", &a, &b, &c)
#define scs(a) scanf("%s", a)
#define pri(x) printf("%d\n", x)
#define prie(x) printf("%d ", x)
#define mp make_pair
#define pb push_back
#define BUFF ios::sync_with_stdio(false);
#define db(x) cerr << #x << " == " << x << endl
#define dbs(x) cerr << x << endl
#define ler freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#define imprime(x, Y)                              \
  for (int X = 0; X < Y; X++) cerr << x[X] << " "; \
  cerr << endl;
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

    ll i, n, a, b, c, d, x, y;
    char pos;

    sc3(n,a,b); sc2(c,d);

    x = a-c;
    y = b-d;

    for( i=0; i<n; i++ ) {
        cin >> pos;
        if( pos=='E' && x<0 ) {
            x++;    
        } else if( pos=='S' && y>0 ) {
            y--;
        } else if( pos=='W' && x>0 ) {
            x--;
        } else if( pos=='N' && y<0 ) {
            y++;
        } 
        if( y==0 && x==0 ) {
            cout << i+1 << endl;
            return 0;
        }
    } 
    cout << -1 << endl;
    return 0;
}
