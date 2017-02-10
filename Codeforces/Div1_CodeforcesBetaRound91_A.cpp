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

vector<long long> vetor;
vector<long long>::iterator it;

void build( ll n ) {
    if( n > 1000000000 ) return;
    vetor.push_back( (n*10)+4 );
    vetor.push_back( (n*10)+7 );

    build( (n*10)+4 );
    build( (n*10)+7 );
}

int main() {
    
    build(0);

    sort( vetor.begin(), vetor.end() );

    ll l, r, cont;

    cont = 0;

    cin >> l >> r;

    while( l <= r ) {
        it = lower_bound(vetor.begin(), vetor.end(), l);
        if( *it <= r ) {
            cont += ((*it - l) + 1) * (*it);
        } else {
            cont += ((r-l)+1) * (*it);
        }
        l = *it + 1;                                 
    }
    cout << cont << endl;
    return 0;
}
