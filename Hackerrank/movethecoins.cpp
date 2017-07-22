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

int contPre;
int contPos;

struct stree {
    int grau;
    int coins;
    int coinsOdd;
    int coinsEven;
    int Pre;
    int Pos;
    int father;
    vector<int> sons;
};

vector< stree > tree; 

void bfs( int atual ) {
    tree[atual].Pre = contPre++;
    
    if( atual!=0 ) {
        if( tree[tree[atual].father].grau==0 ) {
            tree[atual].grau = 1;
            tree[atual].coinsOdd  ^= tree[atual].coins;
        }  else {
            tree[atual].grau = 0;
            tree[atual].coinsEven ^= tree[atual].coins; 
        }
    }
    
    for( int i=0; i<tree[atual].sons.size(); i++ ) {
        if( tree[atual].sons[i] != tree[atual].father ) {
            tree[tree[atual].sons[i]].father = atual;
            bfs( tree[atual].sons[i] ); 
            tree[atual].coinsOdd  ^= tree[tree[atual].sons[i]].coinsOdd;
            tree[atual].coinsEven ^= tree[tree[atual].sons[i]].coinsEven;
        }
    }
    
    tree[atual].Pos = contPos++;                        
}

int main() {
    BUFF;

    int n, q, i, a, b;
    
    cin >> n;

    contPre = contPos = 0;

    tree.resize(n);   
         
    for( i=0; i<n; i++ ) {
        cin >> tree[i].coins;
        tree[i].coinsOdd = 0;
        tree[i].coinsEven = 0;
    }

    for( i=0; i<n-1; i++ ) {
        cin >> a >> b;
        a--; b--;    
        tree[a].sons.pb(b);
        tree[b].sons.pb(a);
    }
    tree[0].father = -1;
    tree[0].grau = 0;
    bfs(0);

    cin >> q;

    for( i=0; i<q; i++ ) {
        cin >> a >> b;
        a--; b--;

        if( (tree[b].Pre > tree[a].Pre && tree[b].Pos < tree[a].Pos) ||
            (tree[b].Pre < tree[a].Pre && tree[b].Pos > tree[b].Pos) ) {
            cout << "INVALID\n";
        } else if( tree[a].grau != tree[b].grau ) {
            if( tree[0].coinsOdd ) cout << "YES\n";
            else cout << "NO\n"; 
        } else {
        	int value = tree[0].coinsOdd;
            value ^= tree[a].coinsOdd;
            value ^= tree[a].coinsEven;
            if( value ) cout << "YES\n";
            else cout << "NO\n";     
        }
    }

    return 0;
}
