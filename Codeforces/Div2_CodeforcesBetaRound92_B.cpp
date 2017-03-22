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

int n, k;

int transf( string word ) {
    int i, res;
    
    res = 0;

    for( i=0; i<k; i++ ) {
        res*=10;
        res+= word[i] - '0';
    }
    return res;
}

int main() {

    int i, j, mini, maxi, res, minDif;

    string init;

    sc2(n,k);

    vector< string > vetor(n);

    vector< int > posi(k);    

    for( i=0; i<n; i++ ) {
        cin >> vetor[i];
    }	

    for( i=0; i<k; i++ ) {
        posi[i] = i;
    }

    minDif = numeric_limits<int>::max();

    do{
        init.clear();
        for( j=0; j<k; j++ ) {
            init += vetor[0][ posi[j] ];
        }
        mini = transf(init);
        maxi = mini;
    

        for( i=1; i<n; i++ ) {
            init.clear();

            for( j=0; j<k; j++ ) {
                init += vetor[i][ posi[j] ];
            }

            res = transf(init);

            mini = min(mini,res);
            maxi = max(maxi,res);
        }    

        minDif = min(minDif,maxi-mini);
    } while( next_permutation(posi.begin(),posi.end()) ); 


    pri(minDif);

	return 0;
}
