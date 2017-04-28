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

ll mod(ll a, ll b){ 
    return ((a+b)+b)%b; 
}


int main() {
    ll a, b, c;
    cin >> a >> b >> c;
    vector<ll> vetor(6);

    vetor[0] = b-a;
    vetor[1] = -a;
    vetor[2] = -b;
    vetor[3] = -b+a;
    vetor[4] = a;
    vetor[5] = b;

    if( c==1 ) cout << mod(a,MOD) << endl;
    else if( c==2 ) cout << mod(b,MOD) << endl;
    else printf("%lld\n", mod(vetor[(c-3)%6],MOD));
    return 0;
}
