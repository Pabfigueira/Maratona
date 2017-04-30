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
    vector<int> ab;
    vector<int> ba;
    int i;

    getline(cin,word);

    for( i=1; i<word.size(); i++ ) {
        if( word[i]=='B' and word[i-1]=='A') ab.push_back(i);
        if( word[i]=='A' and word[i-1]=='B') ba.push_back(i);
    }

    bool certo = false;

    for( i=0; !certo && i<ab.size(); i++ ) {
        if( upper_bound(ba.begin(),ba.end(), ab[i]+1)!=ba.end() ) certo = true;
    }

    for (i=0; !certo && i<ba.size(); i++ ) {
        if( upper_bound(ab.begin(), ab.end(), ba[i]+1)!=ab.end() ) certo = true;
    }
    if( certo ) puts("YES");
    else puts("NO");
    return 0;
}
