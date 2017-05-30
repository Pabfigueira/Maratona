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
    int n, a, b, c, op;
    bool finish;
    vector<int> vetor;

    while( scanf("%d",&n) && n ) { 

        vetor.clear();
        vetor.resize(1e6+10,0);

        finish = false;

        printf("MENSAGEM: [");
   
        while( n ) {
            scanf("%d",&op);
            n--;

            if( finish ) continue;

            if ( op==0 ) {
                finish = true;
            }  else if( op==18 ) {
                scanf("%d%d%d",&a,&b,&c);
                vetor[a] += c;
                vetor[b+1] -= c;
                n-=3;
            } else {
                scanf("%d",&a);
                if( vetor[a] < 0 ) printf(" ");
                else printf("%c",(vetor[a]%26)+'A');
                n--;
            }
        }
        printf("]\n");
    }
	return 0;
}
