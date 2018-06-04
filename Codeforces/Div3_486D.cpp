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
    ll n, i, j, jump;

    scanf("%lld",&n);

    vector<ll> vetor(n);
    set<ll> numbers;
    set<ll>::iterator it, ita;

    for( i=0; i<n; i++ ) {
        scanf("%lld",&vetor[i]);
        numbers.insert(vetor[i]);
    }

    bool foi;

    for( i=0; i<n; i++ ) {
        if( numbers.find(vetor[i]-1)!=numbers.end() and
            numbers.find(vetor[i]+1)!=numbers.end() ) {
            printf("3\n");
            printf("%lld %lld %lld\n",vetor[i], vetor[i]-1, vetor[i]+1);
            return 0;
        }
        foi = false;
        for( j=0; j<30 and !foi; j++ ) {
            jump = 2<<j;
            it  = numbers.find((ll)vetor[i] - jump);
            ita = numbers.find((ll)vetor[i] + jump);
            if( it!=numbers.end() and ita!=numbers.end() ) {
                printf("3\n");
                printf("%lld %lld %lld\n",vetor[i],*it,*ita);
                return 0;
            }
            if( vetor[i]-jump < -1e9+7 ) foi = true;
            if( vetor[i]+jump > 1e9+7 ) foi = true;
        }
    }

    for( i=0; i<n; i++ ) {
        if( numbers.find(vetor[i]-1)!=numbers.end() ) {
            printf("2\n");
            printf("%lld %lld\n",vetor[i],vetor[i]-1);
            return 0;
        }
        if( numbers.find(vetor[i]+1)!=numbers.end() ) {
            printf("2\n");
            printf("%lld %lld\n",vetor[i],vetor[i]+1);
            return 0;
        }
        foi = false;
        for( j=0; j<30; j++ ) {  
            jump = 2<<j;
            it  = numbers.find((ll)vetor[i] - jump);
            ita = numbers.find((ll)vetor[i] + jump);
            if( it!=numbers.end() ) {
                printf("2\n");
                printf("%lld %lld\n",vetor[i],*it);
                return 0;
            }
            if( ita!=numbers.end() ) {
                printf("2\n");
                printf("%lld %lld\n",vetor[i],*ita);
                return 0;
            }
            if( vetor[i]-jump < -1e9+7 ) foi = true;
            if( vetor[i]+jump > 1e9+7 ) foi = true;
        }
    }
    
    printf("1\n%lld\n",vetor[0]);
    return 0;
}
