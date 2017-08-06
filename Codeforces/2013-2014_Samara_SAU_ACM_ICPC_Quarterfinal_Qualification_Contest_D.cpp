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
    BUFF;
    int n, i;
    cin >> n;
    
    vector<string> words(3);
    vector<char> resp(n,'-');

    vector<int> Prob(3,n);

    for( i=0; i<3; i++ ) {
        cin >> words[i];
    }

    for( i=0; i<n; i++ ) {
        if( words[0][i] == words[1][i] and words[1][i]==words[2][i] ) {
            resp[i] = words[0][i];
            Prob[0]--; Prob[1]--; Prob[2]--;            
        } else if( words[0][i]==words[1][i] ) {
            resp[i] = words[0][i];
            Prob[0]--; Prob[1]--;
        } else if( words[0][i]==words[2][i] ) {
            resp[i] = words[0][i];
            Prob[0]--; Prob[2]--;
        } else if( words[1][i]==words[2][i] ) {
            resp[i] = words[1][i];
            Prob[1]--; Prob[2]--;
        }        
    }    
    
    for( i=0; i<n; i++ ) {
        if( resp[i]=='-' ) {
            if( Prob[0]>=Prob[1] and Prob[0]>=Prob[2] ) {
                resp[i] = words[0][i];
                Prob[0]--;
            } else if( Prob[1]>=Prob[0] and Prob[1]>=Prob[2] ) {
                resp[i] = words[1][i];
                Prob[1]--;
            } else {
                resp[i] = words[2][i];
                Prob[2]--;
            }
        } 
    }
    for( i=0; i<n; i++ )
        cout << resp[i];
    cout << endl;
    return 0;
}
