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

int main() {

    ll n, d, a, b, i, soma, fica, qt;

    scanf("%lld %lld", &n, &d);
    
    pair<ll, pair<ll,ll> > atual;
    priority_queue< pair<ll, pair<ll,ll> > > fila;

    for( i=0; i<n; i++ ) {
        scanf("%lld%lld",&a,&b);    
        fila.push( mp(min(a,b), mp(a,b)) );
    }
    
    while( d ) {
        if( fila.size()==0 ) break;
        atual = fila.top();
        fila.pop();
        qt = (atual.second.first/atual.first);
        qt = min(qt,d);
        fica = atual.second.first - (qt*atual.first);
        if( fica > 0 ) fila.push( mp(min(fica,atual.second.second), mp(fica,atual.second.second) ) );
        d-=qt;
    }
    soma = 0;
    while( !fila.empty() ) {
        atual = fila.top();
        fila.pop();
        soma += atual.second.first;
    }
    printf("%lld\n",soma);
    return 0;
}
