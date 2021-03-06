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

vector< set<int> > graphA;
vector< set<int> > graphB;

vector<int> visitedA;
vector<int> visitedB;

int soma, qtdVisitados, deep;

void bfs( int start ) {
    queue< pair<int,int> > fila;
    pair<int,int> atual;

    visitedB[start] = 1;
    fila.push( mp(start,0) );

    while( !fila.empty() ) {
        atual = fila.front();
        fila.pop();

        qtdVisitados++;
        soma += atual.second;
        deep = max(deep,atual.second);
       
 
        for( set<int>::iterator it=graphB[atual.first].begin(); it!=graphB[atual.first].end(); it++ ) {
            if( visitedA[*it]==0 ) {
                visitedA[*it] = 1;
                for( set<int>::iterator ita=graphA[*it].begin(); ita!=graphA[*it].end(); ++ita ) {
                    if( visitedB[*ita]==0 ) {
                        visitedB[*ita] = 1;
                        fila.push( mp(*ita,atual.second+1) );
                    }
                }    
            } 
        } 
    }          
}


int main() {
    BUFF;
    int n, p, i, qt, j,num;
    
    cin >> n >> p;

    soma = 0;
    qtdVisitados = 0;
    deep = 0;

    graphA.resize(n);
    graphB.resize(p);
    visitedA.resize(n,0);
    visitedB.resize(p,0);

    for( i=0; i<n; i++ ) {
        cin >> qt;

        for( j=0; j<qt; j++ ) {
            cin >> num;
            num--;
            graphA[i].insert(num);
            graphB[num].insert(i);        
        }

    }
    bfs(0);
    
    cout << qtdVisitados << " " << deep << " " << soma << endl;
    return 0;
}
