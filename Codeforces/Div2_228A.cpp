#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main() {

    ll n, i, num, pile, qtd;
    
    scanf("%lld",&n);

    map<ll,ll> mapa;
    map<ll,ll>::iterator it;

    for( i=0; i<n; i++ ) {
        scanf("%lld",&num);
        mapa[num]++;
    }

    pile = 0;

    while( mapa.size() > 0 ) {
        pile++;
        it = mapa.begin();
        if( it->second == 1 ) mapa.erase(it->first);
        else mapa[it->first]--;

        qtd = 1;
        while( true ) {
            it = mapa.lower_bound(qtd);
            if( it == mapa.end() ) {
                break;
            }
            if( it->second == 1 ) mapa.erase(it->first);
            else mapa[it->first]--;
            qtd++;
        }
    }

    printf("%lld\n",pile);

    return 0;
}
