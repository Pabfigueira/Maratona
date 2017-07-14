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
#define fi first
#define se second


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

ll max( ll a, ll b ) {
    if( a > b ) return a;
    return b;
}

int main() {
    
    ll n, i, mult, qtd;

    mult = 1;

    scanf("%lld",&n);
    
    vector<ll> vetor(n);
    vector<ll>::iterator it;

    for( i=0; i<n; i++ ) {
        scanf("%lld",&vetor[i]);
    }
    sort(vetor.begin(),vetor.end());

    for( i=n; i>=1; i-- ) {
        it = lower_bound(vetor.begin(),vetor.end(),i);
        qtd = n-distance(vetor.begin(),it);
        mult = (mult*(max(qtd-(n-i),0))) % MOD;
    }
    cout << mult << endl;
    return 0;
}
