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
    
    int n, i, j, qt, h, y;
    string card;

    sc(n);

    stack<string> a;

    for( i=0; i<n; i++ ) {

        y = 0;

        while( !a.empty() ){
            a.pop();
        }
        for( j=0; j<27; j++ ) {
            cin >> card;
            a.push(card);    
        }

        for( j=0; j<3; j++ ) { 
            card = a.top();
            a.pop();
            if( card[0] >= '2' && card[0]<='9' ) qt = 10 - (card[0]-'0');
            else qt = 0;
            
            y += (10  - qt);

            for( h=0; h<qt; h++ ) {
                a.pop();
            }
        }

        for( j=0; j<25; j++ ) { 
            cin >> card;
            a.push(card);
        }

        qt = a.size() - y;
        
        for( j=0; j<qt; j++ ) {
            a.pop();
        }
        cout << "Case " << i+1 << ": ";
        cout << a.top() << endl;
    }

    return 0;
}
