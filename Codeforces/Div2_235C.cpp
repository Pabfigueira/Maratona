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
    ll zero, one, i, qtd;	
    
    string a, b;

    scanf("%lld%lld",&zero,&one);

    if( zero-1>one or one>(2*zero)+2 ) {
        printf("-1\n");
        return 0;
    } 
    if( zero>=one ) {
        for( i=0; i<one+zero; i++ ) {
            if( i%2==0 ) printf("0");
            else printf("1");
        }        
        printf("\n");
        return 0;
    }
    
    if( zero == one/2.0 ) {
        for( i=0; i<one+zero; i++ ) {
            if( i%3==0 ) printf("0");
            else printf("1");
        }
        printf("\n");
        return 0;
    }
    
    if( zero < one/2.0 ) {
        i=0;
        while( zero+one > 0 ) {
            if( i%3==2 ) {
                printf("0");
                zero--;
            } else {
                printf("1");
                one--;
            }
            i++;
        }
        printf("\n");
        return 0;        
    } 
    
    qtd = (2*zero)-one; 
    for( i=0; i<qtd; i++ ) {
        printf("01");
    }
    zero-=qtd;
    one -=qtd;
    i=0; 
    while( zero+one > 0 ) {
        if( i%3==0 ) {
            printf("0");
            zero--;    
        } else {
            printf("1");
            one--;
        }
        i++;
    }
    printf("\n");
    return 0;
}
