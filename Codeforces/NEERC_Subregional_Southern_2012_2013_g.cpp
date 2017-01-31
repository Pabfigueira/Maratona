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

int qt;
vector<string> vetor;
string part;
map< int, set<string> > mapa;

map< string, int > fmapa; 

void generateWords(string atual, int pos) {
    if( pos == qt ) {
        fmapa[atual]++;
        return;
    }
    else {
        generateWords( atual, pos+1);
        atual += "#";
        atual += vetor[pos];    
        generateWords( atual, pos+1);
    }     
}


int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int a, n, i, j, m;

    string query;

    sc(n);
    
    for( a=0; a<n; a++ ) {
        sc(qt);

        vetor.clear();
        vetor.resize(qt);  

        for( j=0; j<qt; j++ ) {
            cin >> vetor[j];
        } 
        sort(vetor.begin(),vetor.end());
        for( i=0; i<qt; i++ ) {
            generateWords(vetor[i],i+1);
        }    
    }

    sc(m);

    for( a=0; a<m; a++ ) {
        sc(qt);

        vetor.clear();
        vetor.resize(qt);  

        for( j=0; j<qt; j++ ) {
            cin >> vetor[j]; 
        }
        
        sort(vetor.begin(),vetor.end());
        
        query = vetor[0];
        for( j=1; j<qt; j++ ) {
            query += "#";
            query += vetor[j];
        }
        
        cout << fmapa[query] << endl;
    }
    return 0;
}
