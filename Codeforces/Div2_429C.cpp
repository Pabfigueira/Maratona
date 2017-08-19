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
#define imprime(x, Y) \
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
    ll n, i, num;

    cin >> n;
    vector<ll> resp(n);
    map<ll,ll> mapa;
    map<ll,ll>::iterator it;
    priority_queue< pair<ll,ll> > fila;

    pair<ll,ll> atual;

    for( i=0; i<n; i++ ) {
        cin >> num;
        mapa[num]++;
    }

    for( i=0; i<n; i++ ) {
        cin >> num;
        fila.push( mp(num,i) );
    }

    while( !fila.empty() ) {
        atual = fila.top();
        fila.pop();
        it = mapa.lower_bound(atual.first);
        it->second--;
        resp[atual.second] = it->first;
        if( mapa[it->first]==0 ) mapa.erase(it->first);
    }
    for( i=0; i<n; i++ ) {
        if( i!=0) cout << " ";
        cout << resp[i];
    }
    cout << endl;

    return 0;
}
