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

#define EPS 0.000001

vector<ll> vetor;

double solve( double number ) {
    ll i;
    double soma = 0.0;
    for( i=0; i<(ll)vetor.size(); i++ ) {
        if( vetor[i]>=number ) soma += vetor[i] - number;
    }
    return soma;
}

double bb( double low, double high, ll a) {
    double mid;

    double result = high;

    for( ll i=0; i<100; i++ ) {
        mid = low + (high-low)/2.;
        
        result = solve(mid);
        
        if( (result - EPS) > (a - EPS) ) {
            low = mid;
        } else {
            high = mid;
        }
    }
    return low;    
}


int main() {
    ll n, a, i, sum, maxi;

    while( scanf("%lld %lld",&n,&a) and n+a!=0 ) {
        vetor.clear();
        vetor.resize(n);
        
        sum = 0;

        for( i=0; i<n; i++ ) {
            scanf("%lld",&vetor[i]);
            sum += vetor[i];
            if( i==0 ) maxi = vetor[i];
            else maxi = max(maxi,vetor[i]);
        }      
        
        if( sum==a ) {
            printf(":D\n");
        } else if( sum < a ) {
            printf("-.-\n"); 
        } else {
            double res;
            res = bb(0.,(double)maxi,a);
            printf("%.4lf\n",res);
        }
    }	
	return 0;
}
