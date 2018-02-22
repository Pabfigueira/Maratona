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
   
    long long int n, i;

    vector<ll> sums;
    set<ll> sets;    
    set<ll>::iterator it;

    sums.push_back(1);
    i = 1;
    while( true ) {
        sets.insert(sums[i-1]);
        if( (i+1)+sums[i-1] > 1e9 ) break;
        sums.push_back(sums[i-1]+(i+1));
        i++;
    }
        
    scanf("%lld",&n);    

    it = sets.begin();    
    while( *it <= n/2 ) {
        if( sets.find(n-(*it))!=sets.end() ) {
            printf("YES\n");
            return 0;
        }          
        it++;
    }  
    printf("NO\n");

    return 0;
}
