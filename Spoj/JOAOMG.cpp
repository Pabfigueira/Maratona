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

bool isEqual( string one, string two, ll quad ) {
    stringstream S, T;
    S << one;
    T << two;
    
    ll num1, num2;

    S >> num1;
    T >> num2;


    if( num1 and num2 and num1+num2 == quad ) return true;
    return false;
}

bool iskaprekar( ll number ) {
    ll i, j, tam, quad = number*number;
    string quadS;

    stringstream S;
    S << quad;
    quadS = S.str();
        
    string one;

    tam = quadS.size();
    
    for( i=0; i<tam-1; i++ ) {
        one += quadS[i];
        string two;
        for( j=i+1; j<tam; j++ ) {
            two+=quadS[j];
        }
        if( isEqual(one,two,number) ) return true;    
    } 
    return false;
}


int main() {
    ll n, i;
    
    vector<ll> group(40005,0);

    group[1] = 1;
    for( i=2; i<=40001; i++ ) {
        if( iskaprekar(i) ) group[i] = 1;    
    }

    
    while( cin >> n && n ) {
        cout << n << ": ";
        if( n<=40001 and group[n] ) cout << "S\n";
        else cout << "N\n";
    }
    
    return 0;
}
