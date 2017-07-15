#include <bits/stdc++.h>

using namespace std;

#define sc(a) scanf("%d", &a)
#define sc2(a,b) scanf("%d %d", &a, &b)
#define sc3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define scs(a) scanf("%s", a)
#define pri(x) printf("%d\n",x)
#define prie(x) printf("%d ", x)
#define mp make_pair
#define pb push_back
#define BUFF ios::sync_with_stdio(false);
#define f first
#define s second
#define fi first
#define se second

typedef long long int ll;
typedef long double ld;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vector<ii> > vvii;

const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3fll;
const ld pi = acos(-1);
const int MOD = 1e9+7;

vector< vector<char> > matriz;
vector< pair<int,int> > vetor;
int a, b;

bool solve() {
    int i, j, x, y, h;
    for( j=0; j<b; j++ ) {
        for( i=0; i<a; i++ ) {
            if( matriz[i][j]=='x' ) {
                matriz[i][j] = '.';
                for( h=0; h<vetor.size(); h++ ) {
                    x = vetor[h].first + j;
                    y = vetor[h].second + i;
                    if( x>=b || y>=a || x<0 || y<0 ) return false;
                    else if (matriz[y][x]!='x') return false;
                    else matriz[y][x] = '.';
                }
            }
        }
    }
    for( i=0; i<a; i++ ) {
        for( j=0; j<b; j++ ) {
            if( matriz[i][j]=='x' ) return false;
        }
    }
    return true;
}

int main() {

    BUFF;
    int t, c, d, i, j, x, y;
    bool first;
    cin >> t;

    vector< vector<char> > pattern;

    while( t-- ) {
        cin >> a >> b >> c >> d;
        matriz.clear();
        matriz.resize(a,vector<char>(b));
        pattern.clear();
        pattern.resize(c,vector<char>(d));
        vetor.clear();

        for( i=0; i<a; i++ ) {
            for( j=0; j<b; j++ ) {
                cin >> matriz[i][j];            
            }
        }
        for( i=0; i<c; i++ ) {
            for( j=0; j<d; j++ ) {
                cin >> pattern[i][j];
            }
        }
        first = true;
        for( j=0; j<d; j++ ) {
            for( i=0; i<c; i++ ) {
                if( pattern[i][j]=='x' ) {
                    if( first ) {
                        first = false;
                        x = j;
                        y = i;
                    } else {
                        vetor.pb( mp(j-x,i-y) );
                    }       
                }
            }
        }
        sort(vetor.begin(),vetor.end());
        if( solve() ) cout << "ANO\n";
        else cout << "NIE\n";
    }
    return 0;
}
