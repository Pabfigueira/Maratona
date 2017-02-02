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
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n, t1, t2, cont, p1, p2, i1, i2;

    cont = 0;

    sc3(n,t1,t2);
    
    p1 = p2 = i1 = i2 = 0;

    if( t1 > t2 ) swap(t1,t2);

    while( cont < n ) {
        i1 = p1;
        p1 += t1;
        cont++;
        if( cont == n ) {
            while( p2 < p1 ) {
                i2 = p2;
                p2 += t2;
                cont++;
            }    
            break;      
        }
        
        if( p2+t2 <= p1+t1 ) {
            i2 = p2;
            p2 += t2;
            cont++;
            if( cont == n ) {
                while( p1 < p2 ) {
                    i1 = p1;
                    p1 += t1;
                    cont++;
                }
                break;
            }
        }  
    }   
    prie(cont);
    pri(max(p1,p2));
    return 0;
}
