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

vector< pair<int,double> > vetor;

vector< vector<int> > dp;

double eleva( double one, double two ) {
    double res = 1;
    
    while( two-- ) {
        res *= one;
    }
    
    return res;
}


double calc( vector<int> V ) {
    double prod = 1;
    for( int i=0; i<V.size(); i++ ) {
        if( V[i] == 0 ) return 0.00;
        prod *= (1.0 - eleva(vetor[i].second,V[i]));    
    }
    return prod;
}

int main() {
    int n, b, i, j;

    while( sc2(n,b) && n+b!=0 ) {
        vetor.clear();
        vetor.resize(n);
        dp.clear();
        dp.resize(1005, vector<int>(n,0) );
        
        for( i=0; i<n; i++ ) {
            scanf("%d %lf",&vetor[i].first,&vetor[i].second);
        }
        
        double resAtual, resNew, maximo;
        vector<int> aux;
        maximo = 0.00;
        for( i=0; i<=b; i++ ) {
            for( j=0; j<n; j++ ) {
                if( i >= vetor[j].first ) {
                    resAtual = calc(dp[i]);
                    aux = dp[i-vetor[j].first];                    
                    aux[j]++;
                    resNew = calc(aux);        
                    
                    if( resNew >= resAtual ) {
                        if( resNew==resAtual ) {
                            int contNew = 0, contAtual=0;
                            for( int h=0; h<n; h++ ) {
                                if( dp[i][h] != 0 ) contAtual++;
                                if( aux[h] != 0 ) contNew++;
                            }
                            if( contNew > contAtual ) dp[i] = aux;
                        } else {
                            dp[i] = aux;
                        }
                    }
                } 
            }
            /*if( i==3 ) {
                for( j=0; j<n; j++ ) {
                    cout << dp[i][j];
                }
                cout << endl;
            }*/
            maximo = max(maximo,calc(dp[i]));    
        } 
        printf("%.3lf\n",maximo);       
    }
    return 0;
}
