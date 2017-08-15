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

map<int,string> mapa;

vector<int> mult3(9);

void solve( string atual, int number, int position ) {
    if( number>1000 ) return;
    if( position>8 ) return;

    if( mapa.find(number)==mapa.end() ) {
        mapa[number] = atual;
        reverse(mapa[number].begin(),mapa[number].end());
    }

    string a, b;

    a = atual;
    b = atual;
  
    b+='-';
    solve(b,number-mult3[position],position+1);

    atual+='+';
    solve(atual,number+mult3[position],position+1);

    a+="0";
    solve(a,number,position+1);
  
}

int main() {
    BUFF;
    int t, number;
  
    mult3[0] = 1;
    mult3[1] = 3;
    mult3[2] = 9;
    mult3[3] = 27;
    mult3[4] = 81;
    mult3[5] = 243;
    mult3[6] = 729;
    mult3[7] = 2187;
    mult3[8] = 6561;
  
    cin >> t;

    solve("",0,0);

    while( t-- ) {
        cin >> number;
        cout << mapa[number] << endl;
    }
    return 0;
}
