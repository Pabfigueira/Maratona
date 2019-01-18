#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {

    ll n, i, m, sol, value;
    
    scanf("%lld",&n);

    vector< pair< pair<ll,ll>,ll> > clients(n); 
    set< pair<ll,ll> > tables;
    set< pair<ll,ll> >::iterator it;
    vector< pair<ll,ll> > resp;
    
    sol = 0;

    for( i=0; i<n; i++ ) {
        scanf("%lld%lld",&clients[i].first.second,&clients[i].first.first);
        clients[i].second = i+1;     
    }

    sort(clients.begin(),clients.end());
    reverse(clients.begin(),clients.end());

    scanf("%lld",&m);

    for( i=0; i<m; i++ ) {  
        scanf("%lld",&value);
        tables.insert( make_pair(value,i+1) );
    }

    for( i=0; i<n; i++ ) {
        it = tables.lower_bound( make_pair(clients[i].first.second, 0) );
        if( it!=tables.end() ) {
            sol += clients[i].first.first;
            resp.push_back( make_pair(clients[i].second, it->second) );
            tables.erase(it); 
        }
    }
    
    printf("%lld %lld\n",(ll)resp.size(),sol);
    for( i=0; i<(ll)resp.size(); i++ ) {
        printf("%lld %lld\n",resp[i].first, resp[i].second);     
    }

    return 0;
}
