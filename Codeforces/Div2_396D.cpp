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
vector<int> p;

int Find( int a ) { return p[a] == a ? a : p[a] = Find(p[a]); }

void Union( int a, int b ) { p[Find(a)] = Find(b); }

bool sameSet( int a, int b ) { return Find(a) == Find(b); }

int main() {
    int n, m, l, i, op;
    string word, word2;

    map<string,int> mapa;

    p.push_back(0);
    p.push_back(1);

    sc3(n,m,l);

    for( i=0; i<n; i++ ) {
        cin >> word;
        mapa[word] = 2*(i+1);
        p.push_back(2*(i+1));
        p.push_back(2*(i+1)+1);
    }


    for( i=0; i<m; i++ ) {
        sc(op);
        cin >> word >> word2;

        if( op == 1 ) {
            if( sameSet( mapa[word], mapa[word2]+1 ) || sameSet( mapa[word2], mapa[word]+1 ) )  {
                puts("NO");
            } else {
                puts("YES");
                Union(mapa[word],mapa[word2]);
                Union(mapa[word]+1,mapa[word2]+1);
            }
        } else {
            if( sameSet( mapa[word], mapa[word2] ) || sameSet( mapa[word]+1, mapa[word2]+1 ) ) {
                puts("NO");
            } else {
                puts("YES");
                Union(mapa[word], mapa[word2]+1);
                Union(mapa[word]+1, mapa[word2]);
            }
        }     
    }

    for( i=0; i<l; i++ ) {
        cin >> word >> word2;

        if( sameSet( mapa[word], mapa[word2] ) ) {
            pri(1);
        } else if( sameSet( mapa[word], mapa[word2]+1 ) ) {
            pri(2);
        } else {
            pri(3);
        }
    }  	
	return 0;
}
