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
    int k, i, tam, j;
    string word;
    cin >> k;

    map<char,int> mapa;
    map<char,int>::iterator it;

    vector<string> ans(k);

    getline(cin,word);
    getline(cin,word);
    tam = word.size();
    for( i=0; i<tam; i++ ) {
        mapa[word[i]]++;        
    }
    	
    for( it=mapa.begin(); it!=mapa.end(); ++it ) {
        if( it->second%k!=0 ) {
            cout << -1 << endl;
            return 0;
        }
        for( i=0; i<k; i++ ) {
            for( j=0; j<it->second/k; j++ ) {
                ans[i] += it->first;
            }
        }     
    }
    for( i=0; i<k; i++ ) {
        cout << ans[i];
    }     
    cout << endl;
	return 0;
}
