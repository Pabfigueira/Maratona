#include <bits/stdc++.h>

using namespace std;

#define sc(a) scanf("%d", &a)
#define sc2(a,b) scanf("%d %d", &a, &b)
#define sc3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define scs(a) scanf("%s", a)
#define pri(x) printf("%d\n",x)
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
    string number;
    ll n, i, j,total;
    cin >> n;

    if( n==1 ) {
        cout << 2 << endl;
        cout << "1A 0X\n";
        cout << "1B 0X\n";
    } else {
        vector<string> vetor;
        for( i=1; i<=n; i++ ) {
            stringstream ss;
            ss << i;
            number = ss.str();
            vetor.pb(number+"A");
        }
        for( i=1; i<=n; i++ ) {
            stringstream ss;
            ss << i;
            number = ss.str();
            vetor.pb(number+"B");
        }
        total = ((n*2)+1)/2;
        cout << total << endl;
        j = 0;
        for( i=0; i<total; i++ ) {
            cout << vetor[j] << " " << vetor[j+1] << endl;
            j+=2;
        }
    }
    return 0;
}
