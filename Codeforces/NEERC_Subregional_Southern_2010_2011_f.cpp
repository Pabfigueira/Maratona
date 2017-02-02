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

    int n, f, i, num, next;

    sc2(n,f);

    queue<int> fila;
    vector<int> toVisit(1000,0);

    for( i=0; i<n; i++ ) {
        cin >> num;
        fila.push(num);
        toVisit[num] = 1;
    }

    bool first = true;

    while( !fila.empty() ) {
        next = fila.front();
        fila.pop();
        
//      cout << "->" << f << " " << next << endl;

        if( f <= next ) {
            for( i=f; i<=next; i++ ) {
                if( toVisit[i] == 1 ) {
                    if( !first ) {
                        cout << " ";
                    } else {
                        first = false;
                    }
                    cout << i;
                    toVisit[i] = 0;
                    f = i;
                }   
            }
        } else {
            for( i=f; i>=next; i-- ){
                if( toVisit[i] == 1 ) {
                    if( !first ) {
                        cout << " ";
                    } else {
                        first = false;
                    }
                    cout << i;
                    toVisit[i] = 0;
                    f = i;
                }   
            }
        }
    }   
    cout << endl;
    return 0;
}
