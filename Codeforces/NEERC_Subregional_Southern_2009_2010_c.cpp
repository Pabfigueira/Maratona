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

vector<string> vetor;

void dfs( int e, int d, int k, bool aberta ) {
    if( e > d ) return;
    
    int last;
    char c;
    
    c = vetor[e][k];
    last = e;

    if( vetor[e][k] == '*' || vetor[e][k] == '#' ) {
        while( last<=d && (vetor[last].size()>k+1 && vetor[last][k]==c )) {
            last++;
        } 
        last--;
    }
    
    if( last == e ) {
        if( aberta ) cout << "<li>\n";
        for(int i=k; i<vetor[e].size(); i++ ) cout << vetor[e][i];
        cout << endl; 
        if( aberta ) cout << "</li>\n";
        dfs(e+1,d,k,aberta); 
    } else {
        if( aberta ) cout << "<li>\n";
        if( c=='*' ) cout << "<ul>\n";
        if( c=='#' ) cout << "<ol>\n";
        dfs(e,last,k+1,true);
        if( c=='#' ) cout << "</ol>\n";
        if( c=='*' ) cout << "</ul>\n"; 
        if( aberta ) cout << "</li>\n";    
        dfs(last+1,d,k,aberta);
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    string s;

    while( getline(cin,s) ) {
        vetor.pb(s);    
    }     
    dfs(0,vetor.size()-1,0,false); 
    return 0;
}
