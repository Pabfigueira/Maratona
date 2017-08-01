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

vector<int> vetor(5);

int solve() {
    // 1
    if( vetor[0]==vetor[1]-1 and vetor[1]==vetor[2]-1 and vetor[2]==vetor[3]-1 and vetor[3]==vetor[4]-1 ) return vetor[0]+200;
    // 2
    if( vetor[0]==vetor[3] or vetor[1]==vetor[4] ) return vetor[2]+180;
    // 3
    if( vetor[0]==vetor[1] and vetor[1]!=vetor[2] and vetor[2]==vetor[4] ) return vetor[2]+160;
    if( vetor[0]==vetor[2] and vetor[2]!=vetor[3] and vetor[3]==vetor[4] ) return vetor[0]+160;
    // 4
    if( vetor[0]!=vetor[1] and vetor[1]!=vetor[2] and vetor[2]==vetor[4] ) return vetor[2]+140;
    if( vetor[0]==vetor[2] and vetor[2]!=vetor[3] and vetor[3]!=vetor[4] ) return vetor[0]+140;
    if( vetor[0]!=vetor[1] and vetor[1]==vetor[3] and vetor[3]!=vetor[4] ) return vetor[1]+140;
    // 5
    if( vetor[0]==vetor[1] and vetor[1]!=vetor[2] and vetor[2]==vetor[3] and vetor[3]!=vetor[4] ) return 3*vetor[2] + 2*vetor[0] + 20;
    if( vetor[0]==vetor[1] and vetor[1]!=vetor[2] and vetor[2]!=vetor[3] and vetor[3]==vetor[4] ) return 3*vetor[3] + 2*vetor[0] + 20;
    if( vetor[0]!=vetor[1] and vetor[1]==vetor[2] and vetor[2]!=vetor[3] and vetor[3]==vetor[4] ) return 3*vetor[3] + 2*vetor[1] + 20;
    //6
    if( vetor[0]==vetor[1] ) return vetor[0];
    if( vetor[1]==vetor[2] ) return vetor[1];
    if( vetor[2]==vetor[3] ) return vetor[2];
    if( vetor[3]==vetor[4] ) return vetor[4];
    // 7
    return 0;
}

int main() {
    int n, teste;
    
    teste = 1;
    cin >> n;
    while( n-- ) {
        cout << "Teste " << teste++ << endl;
        cin >> vetor[0] >> vetor[1] >> vetor[2] >> vetor[3] >> vetor[4];
        sort(vetor.begin(),vetor.end());
        cout << solve() << endl;
        cout << endl;
    }
    return 0;
}
