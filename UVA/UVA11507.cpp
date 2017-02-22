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
vector<string> vetor;

string solve(string atual, int pos) {
    if( pos==n-1 ) return atual;
    if(vetor[pos]=="No") return solve(atual, pos+1);
    if(atual=="+x") return solve(vetor[pos], pos+1);   
    if(atual=="-z") {
        if( vetor[pos] == "-z" ) return solve("-x",pos+1);
        if( vetor[pos] == "+z" ) return solve("+x",pos+1);
        if( vetor[pos] == "+y" ) return solve("-z",pos+1);
        if( vetor[pos] == "-y" ) return solve("-z",pos+1); 
    } else if(atual=="-x") {
        if( vetor[pos] == "-z" ) return solve("+z",pos+1);
        if( vetor[pos] == "+z" ) return solve("-z",pos+1);
        if( vetor[pos] == "+y" ) return solve("-y",pos+1);
        if( vetor[pos] == "-y" ) return solve("+y",pos+1); 
    } else if(atual=="+z") {
        if( vetor[pos] == "-z" ) return solve("+x",pos+1);
        if( vetor[pos] == "+z" ) return solve("-x",pos+1);
        if( vetor[pos] == "+y" ) return solve("+z",pos+1);
        if( vetor[pos] == "-y" ) return solve("+z",pos+1); 
    } else if(atual=="+y") {
        if( vetor[pos] == "-z" ) return solve("+y",pos+1);
        if( vetor[pos] == "+z" ) return solve("+y",pos+1);
        if( vetor[pos] == "+y" ) return solve("-x",pos+1);
        if( vetor[pos] == "-y" ) return solve("+x",pos+1); 
    } else if(atual=="-y") {
        if( vetor[pos] == "-z" ) return solve("-y",pos+1);
        if( vetor[pos] == "+z" ) return solve("-y",pos+1);
        if( vetor[pos] == "+y" ) return solve("+x",pos+1);
        if( vetor[pos] == "-y" ) return solve("-x",pos+1); 
    }
}

int main() {
    int i;
    
    while( sc(n) && n ) {
        vetor.clear();
        vetor.resize(n-1);
    
        for( i=0; i<n-1; i++ ) {
            cin >> vetor[i];
        }

        cout << solve("+x", 0) << endl;
	}
    return 0;
}
