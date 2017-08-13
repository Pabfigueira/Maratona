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
    ll n, k, i, num, two, four, one, atual, qt4, qt3, qt2;

    cin >> n >> k;

    one = 0;
    four = n;
    two = 2*n;

    priority_queue<ll> fila;

    for( i=0; i<k; i++ ) {
        cin >> num;
        fila.push(num);
    }

    while( !fila.empty() ) {
        //cout << one << " " << two << " " << four << endl;
        if( one+four+two == -1 ) break;

        atual = fila.top();
        fila.pop();

        qt4 = min(four,atual/4);
        four -= qt4;
        atual -= qt4*4;

        if( atual==0 ) continue;

        if( four>0 ) {
            if( atual==3 ) {
                atual = 0;
                four--;
                continue;
            }

            if( atual==2 ) {
                if( two>0 ) {
                    atual = 0;
                    two--;
                    continue;
                }
                /*if( one>=2 ) {
                    atual = 0;
                    one-=2;
                    continue;    
                }*/
                atual = 0;
                four--;
                one++;
                continue;
            }
        
            if( atual==1 ) {
                if( one>0 ) {
                    atual = 0;
                    one--;
                    continue;
                }
                /*if( two>0 ) {
                    atual = 0;
                    two--;
                    continue;
                }*/
                atual = 0;
                four--;
                two++;
                continue;
            }
        } 
        
        qt2 = min(two,atual/2);
        two -= qt2;
        atual -= qt2*2;

        if( atual==0 ) continue;

        if( two>0 ) {
            if( one>0 ) {
                atual=0;
                one--;
                continue;
            }
            atual=0;
            two--;
            continue;
        }
     
        if( one>=atual ) {
            one -= atual;
            atual = 0;
            continue;
        } else {
            cout << "NO\n";
            return 0;
        }
    }

    if( fila.size()==0 ) cout << "YES\n";
    else cout << "NO\n";
    return 0;
}
