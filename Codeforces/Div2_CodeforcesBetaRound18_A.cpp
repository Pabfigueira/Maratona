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

vector<int> vetor(6);

bool formed( int a, int b, int c ) {
    if( a == b+c ) return true;
    if( b == a+c ) return true;
    if( c == a+b ) return true;
    return false;
}


bool isTriangle() {
    if( vetor[0] == vetor[2] && vetor[1]==vetor[3] ) return false;
    if( vetor[2] == vetor[4] && vetor[3]==vetor[5] ) return false;
    if( vetor[0] == vetor[4] && vetor[1]==vetor[5] ) return false;

    int a, b, c;
    
    a = (abs(vetor[0]-vetor[2])*abs(vetor[0]-vetor[2])) + (abs(vetor[1]-vetor[3])*abs(vetor[1]-vetor[3]));
    b = (abs(vetor[2]-vetor[4])*abs(vetor[2]-vetor[4])) + (abs(vetor[3]-vetor[5])*abs(vetor[3]-vetor[5]));
    c = (abs(vetor[0]-vetor[4])*abs(vetor[0]-vetor[4])) + (abs(vetor[1]-vetor[5])*abs(vetor[1]-vetor[5]));

    if( formed(a,b,c) ) return true;

    return false;
}


int main() {
	
    int i;

    bool almost;

    almost = false;

    for( i=0; i<6; i++ ) {
        sc(vetor[i]);
    }
    
    for( i=0; i<6; i++ ) {
        if( isTriangle() ) {
            printf("RIGHT\n");
            return 0;
        } else {
            vetor[i]--;
            if( isTriangle() ) {
                almost = true;
            } 
            vetor[i]+=2;
            if( isTriangle() ) {
                almost = true;
            }
            vetor[i]--;
        }
    }
    if( almost ) {
        printf("ALMOST\n");
    } else {
        printf("NEITHER\n");
    }
	return 0;
}
