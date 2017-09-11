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

vector< set<int> > graph;
set<int>::iterator it;

int bfs(int start, int end) {
    vector<int> visited( graph.size(), 0 );
    queue< pair<int,int> > fila;
    pair<int,int> atual;

    fila.push( mp(start,0) );
    visited[start] = 1;

    while( !fila.empty() ) {
        atual = fila.front();
        fila.pop();
        if( atual.first == end ) {
            return atual.second;
        }           
        for( it=graph[atual.first].begin(); it!=graph[atual.first].end(); ++it ) {
            if( visited[*it]==0 ) {
                visited[*it] = 1;
                fila.push( mp(*it,atual.second+1) );
            }
        }
    }  
    return -1;
}

int main() {
    int t, i, iv, a, b;
    string number, inumber;

    graph.resize(100005);

    for( i=0; i<=10001; i++ ) {
        graph[i].insert(i+1);
        stringstream S, iS;
        S << i;
        number = S.str();
        inumber = string(number.rbegin(),number.rend());
        iS << inumber;
        iS >> iv;
        graph[i].insert(iv);         
    }

    scanf("%d",&t);

    for( i=0; i<t; i++ ) {
        scanf("%d%d",&a,&b);
        printf("%d\n",bfs(a,b));     
    } 	
	return 0;
}
