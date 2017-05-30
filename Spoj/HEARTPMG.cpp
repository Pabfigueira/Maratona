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

int ant1( char letter ) {
    if( letter == 'a' ) return 1;
    return 0;
}
int ant2( char letter ) {
    if( letter == 'c' ) return 1;
    return 2;    
}
int eu1( char letter ) {
    if( letter == 'a' ) return 0;
    else if( letter == 'b' ) return 1;
    return 2;
}

ll eleva( ll a, ll b ) {
    ll res = 1;

    while( b-- ) {
        res *= a;
    }
    return res;
}

int main() {
    BUFF;
    ll teste, t, tam, i, x, y, eu, j, maximo;
    string word;

    vector< vector< vector<ll> > > dp;

    cin >> teste;

    for( t=0; t<teste; t++ ) {
        vector<ll> vetor(3);

        cin >> vetor[0] >> vetor[1] >> vetor[2];

        getline(cin,word); 
        getline(cin,word);

        tam = word.size();

        dp.clear();
        dp.resize(tam+1, vector<vector<ll> >(3,vector<ll>(10,0)));       

        maximo = 0;

        for( i=1; i<=tam; i++ ) {
            x = ant1(word[i-1]);
            y = ant2(word[i-1]);
            eu = eu1(word[i-1]);
       
            dp[i][eu][0] = vetor[eu];
            
 
            for( j=0; j<10; j++ ) {
                dp[i][x][j] = dp[i-1][x][j];
                dp[i][y][j] = dp[i-1][y][j];
                    
                if( dp[i][x][j] ) dp[i][eu][0] = max(dp[i][eu][0], dp[i][x][j] + vetor[eu]); 
                if( dp[i][y][j] ) dp[i][eu][0] = max(dp[i][eu][0], dp[i][y][j] + vetor[eu]);
                maximo = max(maximo, dp[i][eu][0]);
            }    

            for( j=1; j<10; j++ ) {
                if( dp[i-1][eu][j-1] ) dp[i][eu][j] = dp[i-1][eu][j-1] + (eleva(2,j) * vetor[eu]);
                maximo = max(maximo,dp[i][eu][j]);  
            }
            if( dp[i-1][eu][9] ) dp[i][eu][9] = (eleva(2,9) * vetor[eu]) + dp[i-1][eu][9];
            maximo = max(maximo,dp[i][eu][9]);             
        }
        cout << maximo << endl; 
    }	
	return 0;
}
