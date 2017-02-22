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

    int n, tamA, tamB, i, sit;

    string wordA, wordB;
    set<char> groupA;
    set<char> groupB, groupC;

    while( sc(n) && n!=-1 ) {
        cin >> wordA >> wordB;
        
        groupA.clear();
        groupB.clear();
        groupC.clear();

        tamA = wordA.size();
        for( i=0; i<tamA; i++ ) {
            groupA.insert(wordA[i]);
        }
        
        sit = 0;

        tamB = wordB.size();
        for( i=0; i<tamB; i++ ) {
            if( groupA.find(wordB[i])!=groupA.end() ) {
                groupA.erase(wordB[i]);
                groupC.insert(wordB[i]);
                if( groupA.size() == 0 && sit == 0 ) sit = 1;
            } else if( groupC.find(wordB[i])==groupC.end() ) {
                groupB.insert(wordB[i]);    
                if( groupB.size() == 7 && sit == 0 ) sit = 2;
            }         
        }
        cout << "Round " << n << endl;
        if( sit == 0 ) cout << "You chickened out.\n";
        if( sit == 1 ) cout << "You win.\n";
        if( sit == 2 ) cout << "You lose.\n";        
    }
	return 0;
}
