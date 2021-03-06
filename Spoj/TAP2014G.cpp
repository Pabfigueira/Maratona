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
    int n, i, acumulate;

    cin >> n;
    
    vector<int> vetor(n);
    vector<int> vetor2;
    vector<int> acumulado(n/2);
    
    for( i=0; i<n; i++ ) {
        cin >> vetor[i];
    }

    sort(vetor.begin(),vetor.end());
    reverse(vetor.begin(),vetor.end());

    for( i=0; i<n; i+=2 ) {
        vetor2.pb( vetor[i]-vetor[i+1] );    
    }
    sort( vetor2.begin(),vetor2.end() );
    reverse( vetor2.begin(), vetor2.end() );
    
    acumulado[vetor2.size()-1] = vetor2[vetor2.size()-1];
    for( i=vetor2.size()-2; i>=0; i-- ) {
        acumulado[i] = acumulado[i+1] + vetor2[i];
    }
    i=0;
    acumulate = 0;
    while( i<vetor2.size() and acumulate<=acumulado[i] ) {
        acumulate += vetor2[i];
        i++;
    } 
    if( acumulate==0 ) cout << -1 << endl;
    else cout << vetor2.size()-i << endl;
    return 0;
}
