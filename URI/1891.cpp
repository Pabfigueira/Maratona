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
#define imprime(x, Y) \
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

    int t, a, n, i, contador;
    
    sc(t);
    
    vector<char> vetor;
    vector<int> resp;
    stack<int> pilha;


    for( a=0; a<t; a++ ) {
        sc(n);
        vetor.clear();
        vetor.resize(n);
        resp.clear();
        
        while( !pilha.empty() ){
            pilha.pop();
        }

        for( i=0; i<n; i++ ) {
            cin >> vetor[i];  
        }

        contador = 0;

        for( i=0; i<n; i++ ) {
            if( vetor[i] == 'B' ) {
                contador++;
                pilha.push(i+1);
            } else {
                resp.push_back(i+1);
                while( !pilha.empty() ) {
                    resp.push_back( pilha.top() );
                    pilha.pop();
                }
                contador = 0;
                if(i+1<n) {
                    if( vetor[i+1] == 'B' ) vetor[i+1] = 'D';
                    else vetor[i+1] = 'B';
                }
            }
        }
        if( contador!=0 )  {
            printf("N\n");
        } else {
            printf("Y\n");
            for( i=0; i<n; i++ ) {
                if( i>0 ) printf(" ");
                printf("%d",resp[i]);
            }
            printf("\n");
        } 
    }

    return 0;
}
