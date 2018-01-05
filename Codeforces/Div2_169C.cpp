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
    BUFF;
    ll n, m, i, esq, dir, soma;

    cin >> n >> m; 

    vector<ll> vetor(n);
    vector<ll> seg(n+1,0);
    vector<ll> ordem;    

    for( i=0; i<n; i++ ) {
        cin >> vetor[i];
    }	
    sort(vetor.begin(),vetor.end());

    for( i=0; i<m; i++ ) {
        cin >> esq >> dir;
        seg[esq-1]++;
        seg[dir]--;
    }
    
    for( i=0; i<n; i++ ) {
        if( i>0 ) seg[i] += seg[i-1];
        ordem.push_back(seg[i]);
    }
    sort(ordem.begin(),ordem.end());

    soma = 0;
    for( i=0; i<n; i++ ) {
        soma += ordem[i]*vetor[i];    
    }
    cout << soma << endl;
	return 0;
}
