#include <bits/stdc++.h>

using namespace std;

#define sc(a) scanf("%lld", &a)
#define sc2(a, b) scanf("%lld%lld", &a, &b)
#define sc3(a, b, c) scanf("%lld%lld%lld", &a, &b, &c)
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

    ll n, m, i, soma, op, num, index;

    sc2(n,m);

    vector<ll> vetor(n);

    map<int,ll> minus;

    soma = 0;

    for( i=0; i<n; i++ ) {
        sc(vetor[i]);
    }
	
    for( i=0; i<m; i++ ) {
        sc(op);
        if( op == 1 ) {
            sc2(index,num);
            index--;
            vetor[index] = num;
            minus[index] = soma;
        } else if( op==2 ) {
            sc(num);
            soma += num;
        } else { 
            sc(index);
            index--;
            printf("%lld\n",soma+vetor[index]-minus[index]);
        }
    }

	return 0;
}
