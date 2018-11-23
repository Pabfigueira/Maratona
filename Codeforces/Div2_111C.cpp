#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main() {

    ll n, k, i, one, two, beginRange, init, multiFirst;

    scanf("%lld%lld",&n,&k);
    
    vector<ll> vetor(n);
    map<ll,ll> mapa;
    map<ll,ll>::iterator it;

    for( i=0; i<n; i++ ) {
        scanf("%lld",&vetor[i]);
        mapa[vetor[i]]++;    
    }
    
    it = mapa.begin();
    init = 0;
    beginRange = (n*it->second)+1;         
    while( beginRange <= k ) {
        init = beginRange;
        it++;
        beginRange += (n*it->second);
    }
    one = it->first;
    multiFirst = it->second;
  
    it = mapa.begin();  
    if( init > 0 ) {
        k -= init;
        k++;
    }
    beginRange = (multiFirst * it->second) + 1;
    while( beginRange <= k ) {
        it++;
        beginRange += (multiFirst * it->second);
    }
    two = it->first;

    printf("%lld %lld\n",one,two);
    return 0;
}
