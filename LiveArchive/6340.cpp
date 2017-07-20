#include <bits/stdc++.h>

using namespace std;

#define sc(a) scanf("%d", &a)
#define sc2(a,b) scanf("%d%d", &a, &b)
#define sc3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define scs(a) scanf("%s", a)
#define pri(x) printf("%d\n",x)
#define pri2(x,y) printf("%d %d\n", x, y)
#define prie(x) printf("%d ", x)
#define mp make_pair
#define pb push_back
#define BUFF ios::sync_with_stdio(false)
#define f first
#define s second

typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vector<ii> > vvii;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<ull> vull;
typedef vector<vull> vvull;

const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3fll;
const ld pi = acos(-1);
const int MOD = 1e9+7;

int main() {
    BUFF;
    ll t, n, m, i, a, b;
    cin >> t;

    vector< set<int> > vetor; 

    while( t-- ) {
        cin >> n >> m;
        vetor.clear();
        vetor.resize(n);
        for( i=0; i<m; i++ ) {
            cin >> a >> b;
            a--; b--;
            vetor[a].insert(b);
            vetor[b].insert(a);
        }
        if( vetor[n-1].size() == 0 ) cout << 2  <<  " " << n << endl;
        else if( vetor[n-1].find(n-2)==vetor[n-1].end() || vetor[n-2].size()>1 ) cout << 1 << endl;
        else cout << 0 << endl;
    }

    return 0;
}
