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

    int n, pages, last, i, init; 

    while( sc(n) && n ) {
        pages = (n+3)/4;
        init = 1;
        last = pages*4;
        
        printf("Printing order for %d pages:\n", n);

        for( i=1; i<=pages; i++ ) {
            printf("Sheet %d, front: ", i);
            if( last > n ) printf("Blank, %d\n", init); 
            else printf("%d, %d\n",last,init);
            init++; last--;
            
            
            if( last > n  && init <= n) printf("Sheet %d, back : %d, Blank\n", i, init);
            else if( init <= n ) printf("Sheet %d, back : %d, %d\n", i, init, last);
            init++; last--;            
        }
        
    }
    return 0;
}
