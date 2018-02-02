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

ll b, s, c, nb, ns, nc, pb, ps, pc, money;

ll bb( ll esq, ll dir ) {
    if( esq==dir ) return esq;
    
    ll mid = (esq+dir+1)/2;
     
    ll price = 0;

    if(b) price += max(0ll, (b*pb*mid) - (pb*nb));  
    if(s) price += max(0ll, (s*ps*mid) - (ps*ns));
    if(c) price += max(0ll, (c*pc*mid) - (pc*nc));
    if( money >= price ) return bb(mid,dir);
    return bb(esq,mid-1);
}


int main() {
    BUFF;

    ll i;

    string receita;

    getline(cin,receita);

    for( i=0; i<receita.size(); i++ ) {
        if( receita[i]=='B' ) b++;
        else if( receita[i]=='S' ) s++;
        else c++;
    }
    
    cin >> nb >> ns >> nc;
    cin >> pb >> ps >> pc;
    cin >> money; 

    cout << bb(0,1000000000000000) << endl;

	return 0;
}
