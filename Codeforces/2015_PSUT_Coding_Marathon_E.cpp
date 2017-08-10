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
    int i, cont;
    cont = 0;

    string ans, resp;

    cin >> ans >> resp;

    for( i=0; i<48; i++ ) {
        if( ans[i]>='a' and ans[i]<='z' ) {
            if( (resp[i]-'A'+'a')!=ans[i] ) cont++;
        }        
    }
    if( cont>=3 ) cout << "Remove\n";
    else cout << "Kafo\n";
    return 0;
}
