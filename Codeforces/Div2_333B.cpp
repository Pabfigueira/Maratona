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

    int n, i, j, range;

    sc(n);

    map<int,int> mapa;
    map<int,int>::iterator init, last;
    vector<int> vetor(n);
    
    for( i=0; i<n; i++ ) {
        sc(vetor[i]);
    }
    
    i = j = range = 0;
    
    while( j<n ) {
        
        while( j<n && ( mapa.size()==0 || (last->first-init->first<=1) ) ) {
            mapa[vetor[j]]++;
            init = mapa.begin();    
            last = mapa.end();
            last--;
            if( last->first - init->first <=1 )
                j++;
        }

        range = max(range,j-i);

        while( (last->first - init->first) > 1 ) {
            if( mapa[vetor[i]] != 1 ) { 
                mapa[vetor[i]]--;
                i++;
            } else {
                mapa.erase(vetor[i]);
                init = mapa.begin();
                last = mapa.end();
                last--;
                i++;
            }
        }
        j++;
    }

    printf("%d\n",range);
    return 0;
}
