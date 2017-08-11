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

const ll timeToSolve = (15*60);
const ll timeLimite  = (3*60*60);
ll n;

vector<ll> vetor;

bool solve( ll monitor ) {
    if( monitor >= n ) return true;
    
    priority_queue<ll,vector<ll>,greater<ll> > fila;
    ll atual; 

    for( ll i=0; i<monitor; i++ ) {
        fila.push(0);
    }
    
    for( ll i=0; i<n; i++ ) {
        atual = fila.top();
        fila.pop();

        if( atual <= vetor[i] ) {
            fila.push(vetor[i] + timeToSolve);
        } else {
            if( atual+timeToSolve-1 >= vetor[i]+timeLimite ) return false;
            fila.push(atual + timeToSolve); 
        }
    }

    return true; 
}

ll bb( ll e, ll d ) {
    if( e==d ) return e;

    ll mid = (e+d)/2;

    if( solve(mid) ) return bb(e,mid);
    return bb(mid+1,d);
}

int main() {
    ll i, h, m, s;
    char op;

    cin >> n;

    vetor.resize(n);

    for( i=0; i<n; i++ ) {
        cin >> h >> op >> m >> op >> s;
        vetor[i] = (h*60*60) + (m*60) + s;
    }	
    sort(vetor.begin(),vetor.end());

    cout << bb(1,n+1) << endl; 
	return 0;
}
