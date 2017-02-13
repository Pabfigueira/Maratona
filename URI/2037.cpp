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
#define ler freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#define imprime(x, Y)                              \
  for (int X = 0; X < Y; X++) cerr << x[X] << " "; \
  cerr << endl;
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

    int n, i, j, contador;
    string word;

    vector< queue<int> > vetor;

    while( sc(n) && n!=-1 ) {
        contador = 0;
        vetor.resize(n+1);
        for( i=2; i<=n; i++ ) {
            cin >> word;
            for( j=0; j<word.size(); j++ ) {
                vetor[i].push( word[j] - '0' );
                contador++;
            }
        }

        while( contador > 0 ) {
            for( i=2; i<=n; i++ ) {
                while( vetor[i].size()>0 && (vetor[i].front()==1 || vetor[ vetor[i].front() ].front()==i) ) {
                    if( vetor[i].front() == 1 ) {
                        vetor[1].push(i);
                        contador--;
                        vetor[i].pop();
                    } else {
                        vetor[ vetor[i].front() ].pop();
                        vetor[i].pop();
                        contador-=2;
                    }    
                } 
            } 
        }

        while( !vetor[1].empty() ) {
            printf("%d",vetor[1].front());
            vetor[1].pop();
        } 
        printf("\n");
    }

    return 0;
}
