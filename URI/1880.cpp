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

bool isPalindrome( string input ) {
    return input == string(input.rbegin(),input.rend());
}

string converte( int n, int base ) {
    string word;
    int resto;
    
    while( n>=base ) {
        resto = n%base;
        n = (n-resto)/base;
        if( resto > 9 ) {
            word += (char)(resto-10 + 'A');
        } else {
            word += (char)(resto+'0');
        }  
    }
    if( n > 9 ) {
        word += (char)(n-10 + 'A');
    } else {
        word += (char)(n+'0');
    } 
    return word;
}

int main() {

    int t, n, a, i;
    vector<int> bases;
    sc(t);
	
    for( a=0; a<t; a++ ) {
        sc(n);   
        bases.clear();

        for( i=2; i<=16; i++ ) {
            if( isPalindrome( converte(n,i) ) ) 
                bases.pb(i);
        }
        
        if( bases.empty() ) pri(-1);
        else {
            printf("%d",bases[0]);
            for( i=1; i<bases.size(); i++ ) {
                printf(" %d",bases[i]);
            }
            printf("\n");
        }
    }

	return 0;
}
