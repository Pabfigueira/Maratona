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
    int i, j, a, b;

    vector< vector<char> > matriz(16,vector<char>(32));

    for( i=0; i<16; i++ ) {
        for( j=0; j<32; j++ ) {
            cin >> matriz[i][j];
            if( matriz[i][j]==':' ) {
                a = i;
                b = j;
            }
        }    
    }   
    string word;
    getline(cin,word);
    getline(cin,word);
    for( i=0; i<word.size(); i++ ) {
        if( word[i]=='<' ) b--;
        else if( word[i]=='v' ) a++;
        else if( word[i]=='>' ) b++;
        else a--;
    }
    if( matriz[a][b]=='E' ) cout << "Yes\n";
    else cout << "No\n";
    return 0;
}
