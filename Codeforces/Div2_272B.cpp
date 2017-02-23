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

string w1, w2;
int tam;
long double total, correct;

void solve( int pos, int res1, int res2 ) {
    if( pos>=tam ) {
        if( res1==res2 ) correct++;
        total++;
        return;                        
    }
    if( w1[pos] == '+' ) res1++;
    else res1--;

    if( w2[pos] == '+' ) {
        solve( pos+1, res1, res2+1);
    } else if( w2[pos] == '-') {
        solve( pos+1, res1, res2-1);
    } else {
        solve( pos+1, res1, res2+1);
        solve( pos+1, res1, res2-1);
    }        
}

int main() {

    cin >> w1;
    cin >> w2;

    tam = w1.size();
    total = correct = 0;
    
    solve(0,0,0);

    long double res = correct/total;

    cout << fixed << setprecision(13) << res << endl;

    return 0;
}
