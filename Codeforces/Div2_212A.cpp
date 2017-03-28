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

vector< vector<char> > matriz;
set< pair<int,int> > hidden;
pair<int,int> one;
pair<int,int> two;

bool solve() {
    set< pair< pair<int,int>, pair<int,int> > > visited;
    queue< pair< pair<int,int>, pair<int,int> > > fila;

    pair<int,int> one2;
    pair<int,int> two2;

    fila.push( mp(one,two) );
    visited.insert( mp(one,two) );

    while( !fila.empty() ) {
        one = fila.front().first;
        two = fila.front().second; 
        fila.pop();

        if( one.first-2>=0 && one.second-2>=0 ) {

            if( two.first-2>=0 && two.second-2>=0 ) {

                one2.first = one.first - 2; one2.second = one.second - 2; 
                two2.first = two.first - 2; two2.second = two.second - 2;

                if( one2 == two2 && hidden.find( one2 ) == hidden.end() ) return true;
                if( visited.find( mp( one2, two2 ) ) == visited.end() ){
                    visited.insert( mp(one2,two2) );
                    fila.push( mp(one2,two2) );
                }
            }
            if( two.first-2>=0 && two.second+2<8 ) {
                one2.first = one.first - 2; one2.second = one.second - 2; 
                two2.first = two.first - 2; two2.second = two.second + 2;

                if( one2 == two2 && hidden.find( one2 ) == hidden.end() ) return true;
                if( visited.find( mp( one2, two2 ) ) == visited.end() ){
                    visited.insert( mp(one2,two2) );
                    fila.push( mp(one2,two2) );
                }
            }
            if( two.first+2<8 && two.second-2>=0 ) {
                one2.first = one.first - 2; one2.second = one.second - 2; 
                two2.first = two.first + 2; two2.second = two.second - 2;

                if( one2 == two2 && hidden.find( one2 ) == hidden.end() ) return true;
                if( visited.find( mp( one2, two2 ) ) == visited.end() ){
                    visited.insert( mp(one2,two2) );
                    fila.push( mp(one2,two2) );
                }
            }  
            if( two.first+2<8 && two.second+2<8 ) {
                one2.first = one.first - 2; one2.second = one.second - 2; 
                two2.first = two.first + 2; two2.second = two.second + 2;

                if( one2 == two2 && hidden.find( one2 ) == hidden.end() ) return true;
                if( visited.find( mp( one2, two2 ) ) == visited.end() ){
                    visited.insert( mp(one2,two2) );
                    fila.push( mp(one2,two2) );
                }
            }
        }

        if( one.first-2>=0 && one.second+2<8 ) {
            if( two.first-2>=0 && two.second-2>=0 ) {

                one2.first = one.first - 2; one2.second = one.second + 2; 
                two2.first = two.first - 2; two2.second = two.second - 2;

                if( one2 == two2 && hidden.find( one2 ) == hidden.end() ) return true;
                if( visited.find( mp( one2, two2 ) ) == visited.end() ){
                    visited.insert( mp(one2,two2) );
                    fila.push( mp(one2,two2) );
                }
            }
            if( two.first-2>=0 && two.second+2<8 ) {
                one2.first = one.first - 2; one2.second = one.second + 2; 
                two2.first = two.first - 2; two2.second = two.second + 2;

                if( one2 == two2 && hidden.find( one2 ) == hidden.end() ) return true;
                if( visited.find( mp( one2, two2 ) ) == visited.end() ){
                    visited.insert( mp(one2,two2) );
                    fila.push( mp(one2,two2) );
                }
            }
            if( two.first+2<8 && two.second-2>=0 ) {
                one2.first = one.first - 2; one2.second = one.second + 2; 
                two2.first = two.first + 2; two2.second = two.second - 2;

                if( one2 == two2 && hidden.find( one2 ) == hidden.end() ) return true;
                if( visited.find( mp( one2, two2 ) ) == visited.end() ){
                    visited.insert( mp(one2,two2) );
                    fila.push( mp(one2,two2) );
                }
            }  
            if( two.first+2<8 && two.second+2<8 ) {
                one2.first = one.first - 2; one2.second = one.second + 2; 
                two2.first = two.first + 2; two2.second = two.second + 2;

                if( one2 == two2 && hidden.find( one2 ) == hidden.end() ) return true;
                if( visited.find( mp( one2, two2 ) ) == visited.end() ){
                    visited.insert( mp(one2,two2) );
                    fila.push( mp(one2,two2) );
                }
            }
        }

        if( one.first+2<8 && one.second-2>=0 ) {
            if( two.first-2>=0 && two.second-2>=0 ) {

                one2.first = one.first + 2; one2.second = one.second - 2; 
                two2.first = two.first - 2; two2.second = two.second - 2;

                if( one2 == two2 && hidden.find( one2 ) == hidden.end() ) return true;
                if( visited.find( mp( one2, two2 ) ) == visited.end() ){
                    visited.insert( mp(one2,two2) );
                    fila.push( mp(one2,two2) );
                }
            }
            if( two.first-2>=0 && two.second+2<8 ) {
                one2.first = one.first + 2; one2.second = one.second - 2; 
                two2.first = two.first - 2; two2.second = two.second + 2;

                if( one2 == two2 && hidden.find( one2 ) == hidden.end() ) return true;
                if( visited.find( mp( one2, two2 ) ) == visited.end() ){
                    visited.insert( mp(one2,two2) );
                    fila.push( mp(one2,two2) );
                }
            }
            if( two.first+2<8 && two.second-2>=0 ) {
                one2.first = one.first + 2; one2.second = one.second - 2; 
                two2.first = two.first + 2; two2.second = two.second - 2;

                if( one2 == two2 && hidden.find( one2 ) == hidden.end() ) return true;
                if( visited.find( mp( one2, two2 ) ) == visited.end() ){
                    visited.insert( mp(one2,two2) );
                    fila.push( mp(one2,two2) );
                }
            }  
            if( two.first+2<8 && two.second+2<8 ) {
                one2.first = one.first + 2; one2.second = one.second - 2; 
                two2.first = two.first + 2; two2.second = two.second + 2;

                if( one2 == two2 && hidden.find( one2 ) == hidden.end() ) return true;
                if( visited.find( mp( one2, two2 ) ) == visited.end() ){
                    visited.insert( mp(one2,two2) );
                    fila.push( mp(one2,two2) );
                }
            }
        }  

        if( one.first+2<8 && one.second+2<8 ) {
            if( two.first-2>=0 && two.second-2>=0 ) {

                one2.first = one.first + 2; one2.second = one.second + 2; 
                two2.first = two.first - 2; two2.second = two.second - 2;

                if( one2 == two2 && hidden.find( one2 ) == hidden.end() ) return true;
                if( visited.find( mp( one2, two2 ) ) == visited.end() ){
                    visited.insert( mp(one2,two2) );
                    fila.push( mp(one2,two2) );
                }
            }
            if( two.first-2>=0 && two.second+2<8 ) {
                one2.first = one.first + 2; one2.second = one.second + 2; 
                two2.first = two.first - 2; two2.second = two.second + 2;

                if( one2 == two2 && hidden.find( one2 ) == hidden.end() ) return true;
                if( visited.find( mp( one2, two2 ) ) == visited.end() ){
                    visited.insert( mp(one2,two2) );
                    fila.push( mp(one2,two2) );
                }
            }
            if( two.first+2<8 && two.second-2>=0 ) {
                one2.first = one.first + 2; one2.second = one.second + 2; 
                two2.first = two.first + 2; two2.second = two.second - 2;

                if( one2 == two2 && hidden.find( one2 ) == hidden.end() ) return true;
                if( visited.find( mp( one2, two2 ) ) == visited.end() ){
                    visited.insert( mp(one2,two2) );
                    fila.push( mp(one2,two2) );
                }
            }  
            if( two.first+2<8 && two.second+2<8 ) {
                one2.first = one.first + 2; one2.second = one.second + 2; 
                two2.first = two.first + 2; two2.second = two.second + 2;

                if( one2 == two2 && hidden.find( one2 ) == hidden.end() ) return true;
                if( visited.find( mp( one2, two2 ) ) == visited.end() ){
                    visited.insert( mp(one2,two2) );
                    fila.push( mp(one2,two2) );
                }
            }
        }
 
    }


    return false;
}


int main() {

    int n, i, j, a;

    bool first;

    sc(n);

    for( a=0; a<n; a++ ) {

        matriz.clear();
        matriz.resize(8,vector<char>(8));
        hidden.clear();
        first = false;

        for( i=0; i<8; i++ ) {
            for( j=0; j<8; j++ ) {
                cin >> matriz[i][j];
                if( matriz[i][j] == 'K' ) {
                    if( !first ) { 
                        first = true;
                        one.first = i;
                        one.second = j;
                    } else {
                        two.first = i;
                        two.second = j;
                    } 
                } else if( matriz[i][j] == '#' ) {
                    hidden.insert( mp(i,j) );
                } 
            }
        }

        if( solve() ) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
