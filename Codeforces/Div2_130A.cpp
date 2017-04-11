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
    string word;

    int i;
    
    getline(cin,word);
    string ans;
    string last;

    if( word.size() < 3 ) {
        cout << word << endl;
        return 0;
    }

    last += word[0];
    last += word[1];
    last += word[2];

    for( i=3; i<word.size(); i++ ) {
        if( last == "WUB" ) {
            if( ans.size()>0 && ans[ans.size()-1]!=' ' ) 
                ans += " ";
            last[0] = '-';
            last[1] = '-';
            last[2] = word[i];    
        } else {
            if( last[0] != '-' )
                ans += last[0];
            last[0] = last[1];
            last[1] = last[2];
            last[2] = word[i];
        }
    }
    if( last!="WUB" ) {
        if( last[0]!='-' ) ans+=last[0];
        if( last[1]!='-' ) ans+=last[1];
        if( last[2]!='-' ) ans+=last[2];
    }
    cout << ans << endl;
	return 0;
}
