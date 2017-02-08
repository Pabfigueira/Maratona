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

vector< pair<int, pair<int,int> > > vetor;

int distance( int x, int y, int x2, int y2 ) {
    return abs(x-x2) + abs(y-y2);
}

int main() {
    int a, b, c, i, n, j;

    sc(n);
    
    for( i=0; i<n; i++ ) {
        sc3(a,b,c);
        if( distance(6,6,a,b) <= c ) {
            vetor.push_back( make_pair(c, make_pair(a,b)) );
        }
    }
    sort(vetor.begin(),vetor.end());
	vector<int> pd(vetor.size(),1);
    
    for( i=0; i<vetor.size(); i++ ) {
        for( j=i+1; j<vetor.size(); j++ ) {
            if( distance(vetor[i].second.first,vetor[i].second.second, vetor[j].second.first, vetor[j].second.second) 
                <= vetor[j].first - vetor[i].first ) {
                pd[j] = max(pd[j],1+pd[i]); 
            } 
        }
    }

    int maximo = 0;
    for( i=0; i<vetor.size(); i++ ) {
        maximo = max(maximo,pd[i]);
    }
    pri(maximo);
    return 0;
}
