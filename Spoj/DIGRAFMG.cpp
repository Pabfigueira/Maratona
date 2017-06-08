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
    int n, i, j, num, p, minimo;
    bool fail;

    vector<int> in;

    while( sc(n) && n ) { 
        in.clear();
        in.resize(1001,0);
        fail = false;

        for( i=0; i<n; i++ ) {
            sc(num);
            in[num]++;
        }    

        for( i=0; i<n; i++ ) {
            sc(num);
            p = in[1000];
            for( j=1000; j>0 && num && !fail; j-- ) {
                minimo = min(p,num);
                p = in[j-1];
                in[j] -= minimo;
                in[j-1] += minimo;
                num-=minimo;    
            }
            if( num>0 ) fail = true;
        }

        if( in[0]!=n ) fail = true;

        if( fail ) printf("N\n");
        else printf("E\n");
    }
    return 0;
}
