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

bool isPrime( ll n ) {
	if( n < 0 ) return isPrime(-n);
	if( n<5 || n%2==0 || n%3==0 ) return (n==2 || n==3);
	ll maxP = sqrt(n) + 2;
	for( ll p=5; p<maxP; p+=6 ){
		if( n%p == 0 || n % (p+2) == 0 ) return false;
	}
	return true;
}


int main() {

	ll a, b;
	bool am, aM, bm, bM; 
	scanf("%lld%lld",&a,&b);

	am = isPrime(a-2);
	aM = isPrime(a+2);

	if( !am && !aM && a!=2 ) {
		printf("Unlucky Benny\n");
		return 0;
	}
	
	bm = isPrime(b-2);
	bM = isPrime(b+2);
	
	if( !bm && !bM ) {
		printf("Unlucky Benny\n");
		return 0;
	}

	if( aM && a+2==b ) {
		printf("%lld->%lld\n",a,b);
		return 0;
	}

	if( aM && a+4==b ) {
		printf("%lld->%lld->%lld\n",a,a+2,b);
		return 0;
	}
	
	/*if( (am&&aM) || (bm&&bM) ) {
		printf("Poor Benny\n");
		return 0;
	}*/


	if( a==2 ) {
		if( bm ) 
			printf("%lld->%lld\n",a,b);
		else
			printf("%lld->%lld->%lld\n",a,b+2,b);
		return 0;
	}

	printf("%lld",a);
	
	if(am) printf("->2->");
	else printf("->%lld->2->",a+2);

	if(bm) printf("%lld\n",b);
	else printf("%lld->%lld\n",b+2,b);

	return 0;
}
