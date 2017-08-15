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

int k, n;

vector< pair<int, pair<int,int> > > group;
vector< pair<int, pair<int,int> > >::iterator it;

bool dfs( int node, vector<set<int> >& graph, vector<int>& color) {
    color[node] = 1;
    
    for( set<int>::iterator ita = graph[node].begin(); ita!=graph[node].end(); ++ita ) {
        if( color[*ita]==1 ) return true; 
        else if( color[*ita]==0 ) {
            if( dfs(*ita,graph,color) ) return true;
        }
    }

    color[node] = 2;

    return false;
}


bool IsCycled( vector<set<int> >& graph ) {
    vector<int> color(graph.size(),0);

    for( int i=0; i<graph.size(); i++ ) {
        if( color[i]==0 ) {
            if( dfs(i,graph, color) ) return true;
        }
    }
    return false;
}

bool solve() {
    int num, j;    

    vector<set<int> > graph;

    for( num=0; num< ((1<<k)/2); num++ ) {
        
        graph.clear();
        graph.resize(n);

        for( j=0; j<k; j++ ) {
            if( num & (1<<j) ) {
                graph[ group[j].first ].insert( group[j].second.first );
                graph[ group[j].second.first ].insert( group[j].second.second ); 
            } else {
                graph[ group[j].second.second ].insert( group[j].second.first );
                graph[ group[j].second.first ].insert( group[j].first );
            }
        } 

        if( !IsCycled(graph) ) return true;
    }

    return false;        
}

int main() {
    BUFF;
    int i, a, b, c;

    cin >> n >> k;  

    group.resize(k);

    for( i=0; i<k; i++ ) {
        cin >> a >> b >> c;    
        a--; b--; c--;
        if( c<a ) swap(a,c);
        group[i] = ( mp(a,mp(b,c)) );
    }

    if( solve() ) cout << "sim\n";
    else cout <<"nao\n";

    return 0;
}

