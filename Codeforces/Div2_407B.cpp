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

    ll b, q, l, m, value, i, maximo; 

    set<int> group;
    set<int> visited;

    scanf("%lld %lld %lld %lld",&b,&q,&l,&m);

    for( i=0; i<m; i++ ) {
        scanf("%lld",&value);
        group.insert(value);
    }

    maximo = 0;

    while( abs(b) <= l ) {
        if( visited.find(b) != visited.end() ) {
            if( group.find(b) != group.end()  && (q!=-1 || group.find(-b) != group.end()) )
                printf("%lld\n",maximo);
            else    
                printf("inf\n");
            return 0;
        }
        visited.insert(b);
        if( group.find(b) == group.end() )
            maximo++;
        b*=q;
    }   
    printf("%lld\n",maximo);
    return 0;
}
