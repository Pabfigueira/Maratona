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
    vector< pair<int,int> > vetor(3);
    vector< int > resp(4);
    

    sc3(vetor[0].first, vetor[1].first, vetor[2].first);
    vetor[0].second = 0;
    vetor[1].second = 1;
    vetor[2].second = 2;


    sort(vetor.begin(),vetor.end());

    resp[ vetor[0].second + vetor[1].second ] = vetor[0].first;

    vetor[1].first -= vetor[0].first;
    vetor[0].first = 0;

    if( vetor[1].first ) {
        resp[ vetor[1].second + vetor[2].second ] = vetor[1].first;
        vetor[2].first -= vetor[1].first;
        vetor[1].first = 0;
    } 
   
    if( vetor[2].first ) { 
        if( vetor[2].first%2!=0 || vetor[2].first > 2*resp[ vetor[0].second + vetor[1].second ] ) {
            cout << "Impossible\n";
            return 0;
        }
    
        resp[ vetor[0].second + vetor[1].second ] -= vetor[2].first/2;
        resp[ vetor[0].second + vetor[2].second ] += vetor[2].first/2;
        resp[ vetor[1].second + vetor[2].second ] += vetor[2].first/2;
    }
    
    cout << resp[1] << " " << resp[3] << " " << resp[2] << endl;

    return 0;
}
