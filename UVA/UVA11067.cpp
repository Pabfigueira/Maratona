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

    int w, h, n, i, x, y;

    vector< vector<long long int> > matriz;

    while( sc2(w,h) && (w||h) ) {
        matriz.clear();
        matriz.resize(w+1,vector<long long int>(h+1,0));
        sc(n);
        for( i=0; i<n; i++ ) {
            sc2(x,y);
            matriz[x][y] = -1;
        } 
        y=0; 
        while( y<=h && matriz[0][y]!=-1 ) {
            matriz[0][y] = 1;
            y++;
        }
        x=0;
        while(x<=w && matriz[x][0]!=-1 ) {
            matriz[x][0] = 1;
            x++;
        }

        for( y=1; y<=h; y++ ) {
            for( x=1; x<=w; x++ ) {
                if( matriz[x][y] != -1 ) {
                    if( matriz[x-1][y] != -1 ) matriz[x][y] += matriz[x-1][y];
                    if( matriz[x][y-1] != -1 ) matriz[x][y] += matriz[x][y-1];
                }
            }
        }
        if( matriz[w][h] == 0 ) printf("There is no path.\n");
        else if( matriz[w][h] == 1 ) printf("There is one path from Little Red Riding Hood's house to her grandmother's house.\n");
        else printf("There are %lld paths from Little Red Riding Hood's house to her grandmother's house.\n", matriz[w][h]);
    }

    return 0;
}

