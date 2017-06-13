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
    int n, i, hour, nour, tank, atual;

    vector<int> fuel;
    vector<int> dist;
    
    while( sc(n) && n ) {
        fuel.clear();
        fuel.resize(n);
        dist.clear();
        dist.resize(n);

        hour = -1;
        nour = -1;

        for( i=0; i<n; i++ ) {
            sc(fuel[i]);
        }     
        for( i=0; i<n; i++ ) {
            sc(dist[i]);
        }

        bool fail;

        for( i=0; i<n && hour==-1; i++ ) {
            fail = false;
            tank = 0;
            atual = i;
            do{
                tank += fuel[atual];
                if( tank < dist[atual] ) {
                    fail = true;
                    break;
                }
                tank -= dist[atual];
                atual++;
                if( atual==n ) atual = 0;
            } while( atual!=i );
            if(!fail) hour = i+1;
        }
        
        for( i=0; i<n && nour==-1; i++ ) {
            fail = false;
            tank = 0;
            atual = i;
            do{
                tank += fuel[atual];
                int next = atual-1;
                if( next == -1 ) next = n-1;
                if( tank < dist[next] ) {
                    fail = true;
                    break;
                }
                tank -= dist[next];
                atual = next;
            } while( atual!=i );
            if(!fail) nour = i+1;
        }



        printf("%d %d\n",hour,nour);
    }
    return 0;
}
