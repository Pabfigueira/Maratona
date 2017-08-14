#include <bits/stdc++.h>

using namespace std;

#define sc(a) scanf("%d", &a)
#define sc2(a, b) scanf("%d%d", &a,&b)
#define sc3(a, b, c) scanf("%d%d%d",&a, &b,&c)
#define scs( a ) scanf("%s", a)
#define pri(x) printf("%d\n", x)
#define prie(x) printf("%d ", x)
#define mp make_pair
#define pb push_back
#define BUFF ios::sync_with_stdio(false);
#define f first
#define s second

typedef long long int ll;
typedef long double ld;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vector<ii> > vvii;

const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3fll;
const ld pi = acos(-1);
const int MOD = 1e9+7;

int main() {
    BUFF;
    string word;
    int i, cont;
    getline(cin,word);

    if( word.size()==1 ) {
        cout << word[0] << 1 << endl;
        return 0;
    }
    cont = 1;
    i=1;

    while( i<word.size() ) {
        while( i<word.size() and word[i]==word[i-1] ) {
            i++;
            cont++;
        }
        cout << word[i-1] << cont;
        cont = 1;
        i++;
    }
    cout << word[word.size()-1] << cont << endl;
    cout << endl;
    return 0;
}
