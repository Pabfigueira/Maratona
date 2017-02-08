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
int n;
vector<int> vetor;

pair<int,vector<int> > dp(int index, int timeLeft, vector<int> aux) {
    if( index == n || timeLeft==0 ) return make_pair(timeLeft,aux);
    if( vetor[index] > timeLeft ) return dp(index+1, timeLeft,aux);               
    pair<int, vector<int> > a, b;

    a = dp(index+1,timeLeft-vetor[index],aux);
    b = dp(index+1,timeLeft,aux);
    
    if( a <= b ){
        a.second.push_back(vetor[index]);
        return a;    
    }
    return b;
}

int main() {
    int size, i;
    pair<int, vector<int> > res;
    vector<int> aux;

    while( sc(size) != EOF ) {
        sc(n);
        vetor.clear();
        vetor.resize(n);

        for( i=0; i<n; i++ ) {
            sc(vetor[i]);
        }
        
        aux.clear();
        res = dp(0,size,aux);

        printf("%d",res.second[res.second.size()-1]);
        for( i=res.second.size()-2; i>=0; i-- ) {
            printf(" %d", res.second[i]);    
        }
        printf(" sum:%d\n",size-res.first);
    }
	
	return 0;
}
