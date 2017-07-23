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

typedef unsigned long long int ll;
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

string word;

ll solve() {
    vector< vector< vector<ll> > > dp( word.size()+1, vector< vector<ll> >(10,vector<ll>(2,0)) );    

    int i, j, k;

    for( i=0; i<word[0]-'0'; i++ ) {
        if( i!=4 ) 
            dp[1][i][1] = 1;
    }
    if( word[0]-'0' != 4 ) 
        dp[1][word[0]-'0'][0] = 1;

    for( i=2; i<=word.size(); i++ ) {
        for( j=0; j<=9; j++ ) {
            if( j!=4 ) {
                
                if( j>word[i-1]-'0' ) {
                    for( k=0; k<=9; k++ ) {
                        if( j!=3 || k!=1 ) dp[i][j][1] += dp[i-1][k][1];
                    }     
                }

                if( j<word[i-1]-'0' ) {
                    for( k=0; k<=9; k++ ) {
                        if( j!=3 || k!=1 ) dp[i][j][1] += dp[i-1][k][0] + dp[i-1][k][1];
                    }
                }

                if( j==word[i-1]-'0' ) {
                    for( k=0; k<=9; k++ ) {
                        if( j!=3 || k!=1 ) dp[i][j][0] += dp[i-1][k][0];
                    
                        if( j!=3 || k!=1 ) dp[i][j][1] += dp[i-1][k][1];
                    }
                }

            } 
        }    
    }

    ll sum = 0;

    for( i=0; i<=9; i++ ) {
        sum += dp[word.size()][i][1];
    }
    return sum;
}

ll num;

ll bb( ll e, ll d ) {
    ll mid = e +  (d-e) / 2; 
    
    if( e==d ) return e;

    stringstream S;
    S << mid;
    word = S.str();
    if( solve()>num ) return bb(e,mid);
    return bb(mid+1,d);
}


int main() {
    BUFF;
    while( cin >> num ) {
        cout << bb(num,numeric_limits<ll>::max())-1 << endl;
    }

    return 0;
}
