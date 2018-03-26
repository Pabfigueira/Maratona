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

int main() {
    int white, black, sol1, sol2, w, b, i;

    cin >> white >> black;

    sol1 = sol2 = 0;

    w = white;
    b = black;
    vector<int> vetor(white+black,0);
    if( w>0 ) {
        w--;
    } else {
        vetor[0]=1;
        b--;
    }
    for( i=1; i<white+black; i++ ) {
        if( i%2==0 ) {
            if( vetor[i-1]==0 ) {
                if( w ) {
                    w--; vetor[i] = 0;
                } else {
                    b--; vetor[i] = 1;
                }
            } else {
                if( b ) {
                    b--; vetor[i] = 1;
                } else {
                    w--; vetor[i] = 0;
                }
            } 
        } else {
            if( vetor[i-1]==0 ) {
                if( b ) {
                    b--; vetor[i] = 1;
                } else {
                    w--; vetor[i] = 0;
                }
            } else {
                if( w ) {
                    w--; vetor[i] = 0;
                } else {
                    b--; vetor[i] = 1;
                }
            }
        }
        if( vetor[i]==vetor[i-1] ) sol1++;
    }
    w = white;
    b = black;
    if( b ) {
        b--;
        vetor[0] = 1;
    } else {
        w--;
        vetor[0] = 0;
    }
    for( i=1; i<white+black; i++ ) {
        if( i%2==0 ) {
            if( vetor[i-1]==0 ) {
                if( w ) {
                    w--; vetor[i] = 0;
                } else {
                    b--; vetor[i] = 1;
                }
            } else {
                if( b ) {
                    b--; vetor[i] = 1;
                } else {
                    w--; vetor[i] = 0;
                }
            } 
        } else {
            if( vetor[i-1]==0 ) {
                if( b ) {
                    b--; vetor[i] = 1;
                } else {
                    w--; vetor[i] = 0;
                }
            } else {
                if( w ) {
                    w--; vetor[i] = 0;
                } else {
                    b--; vetor[i] = 1;
                }
            }
        }
        if( vetor[i]==vetor[i-1] ) sol2++;
    }
    cout << max(sol1,sol2) << " " << (white+black-1)-max(sol1,sol2) << endl;
    return 0;
}
