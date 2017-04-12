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
    int n, i, num;
    sc(n);	
    map<int,int> mapa;
    bool fail = false;

    for( i=0; i<n; i++ ) {
        sc(num);
        mapa[num]++;
        if( num==5 || num==7 ) fail = true;        
    }
    if( mapa[3] > mapa[6] ) fail = true;
    if( mapa[4] > mapa[2] ) fail = true;
    if( mapa[2] != (mapa[6]-mapa[3]) + mapa[4] ) fail = true;
    if( mapa[1] != n/3 ) fail = true;

    if( fail ) printf("-1\n");
    else {
        vector< vector<int> > grupos(n/3,vector<int>(3,0));
        for( i=0; i<n/3; i++ ) { grupos[i][0] = 1; }
        while( mapa[3]!=0 ) {
            i=0;
            while( grupos[i][1]!=0 ) i++;
            grupos[i][1] = 3;
            grupos[i][2] = 6;
            mapa[3]--;
            mapa[6]--;
        }
        while( mapa[6]!=0 ) {
            i=0;
            while( grupos[i][2]!=0 ) i++;
            grupos[i][1] = 2;
            grupos[i][2] = 6;
            mapa[2]--;
            mapa[6]--;
        }
        while( mapa[4]!=0 ) {
            i=0; 
            while( grupos[i][2]!=0 ) i++;
            grupos[i][1] = 2;
            grupos[i][2] = 4;
            mapa[2]--;
            mapa[4]--;
        }
        for( i=0; i<n/3; i++ ) {
            cout << grupos[i][0] << " " << grupos[i][1] << " " << grupos[i][2] << endl;
        }
    }
	return 0;
}
