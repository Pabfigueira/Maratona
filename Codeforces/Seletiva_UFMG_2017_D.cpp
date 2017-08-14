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
    ll n, num ,i;

    vector<ll> vetor(1e7+4,0);

    vetor[1] = 1;
    vetor[2] = 1;

    for( i=3; i<=1e7+2; i++ ) {
        vetor[i] = vetor[i-1] + vetor[i-2] -vetor[i-3];
    }

    cin >> n;

    for( i=0; i<n; i++ ) {
        cin >> num;
        cout << vetor[num] << endl;
    }
    return 0;
}
