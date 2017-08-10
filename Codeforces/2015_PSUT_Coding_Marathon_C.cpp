#include <bits/stdc++.h>

using namespace std;

#define sc(a) scanf("%d", &a)
#define sc2(a, b) scanf("%d%d", &a,&b)
#define sc3(a, b, c) scanf("%d%d%d",&a, &b,&c)
#define scs( a ) scanf("%s", a)
#define pri(x) printf("%d\n", x)
#define prie(x) printf("%d ", x)
#define mp make_pair
#define pb push_back
#define BUFF ios::sync_with_stdio(false);
#define f first
#define s second

typedef long long int ll;
typedef long double ld;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vector<ii> > vvii;

const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3fll;
const ld pi = acos(-1);
const int MOD = 1e9+7;

int main() {
    int n, m, x, y, z;

    cin >> n >> m >> x >> y >> z;

    if( m ) {
        if( m>=x ) {
            m-=x;
            x = 0;    
        } else {
            x-=m;
            m=0;
        }
    }
    
    if( m ) {
        if( m>=y ) {
            m-=y;
            y = 0;
        } else {
            y-=m;
            m=0;
        }
    }

    if( m ) {
        if( m>=z ) {
            m-=z;
            z = 0;
        } else {
            z-=m;
            m = 0;
        }
    }

    if( m==0 and x+(2*y)+(3*z) >= n ) {
        cout << "Yes\n";    
    } else {
        cout << "No\n";
    }

    return 0;
}
