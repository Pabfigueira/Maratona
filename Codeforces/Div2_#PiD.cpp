#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main() {

    ll n, k, tam, m, fill, i, quant;
    
    scanf("%lld%lld%lld",&n,&k,&tam);

    map<ll,pair<ll,ll> > intervals;
    map<ll,pair<ll,ll> >::iterator it;
    
    pair<ll, pair<ll,ll> >itCopy;

    intervals[1] = make_pair(n,(n+1)/(tam+1));
    fill = (n+1)/(tam+1);
    
    scanf("%lld",&m);
    vector<ll> plays(m);

    for( i=0; i<m; i++ ) {
        scanf("%lld",&plays[i]);    
    }
    i=0;
    while( i<m ) {
        it = intervals.upper_bound(plays[i]);
        it--;
        fill -= it->second.second;
        
        itCopy.first = it->first;
        itCopy.second = it->second;
        intervals.erase(it);

        if( itCopy.first != itCopy.second.first ) {
            if( itCopy.first == plays[i] ) {
                quant = (itCopy.second.first - (itCopy.first+1))+1;
                intervals[itCopy.first + 1] = make_pair(itCopy.second.first,floor((quant+1)/(tam+1)) );
                fill += intervals[itCopy.first+1].second; 
            } else if( itCopy.second.first == plays[i] ) {
                quant = ((itCopy.second.first-1) - itCopy.first)+1;
                intervals[itCopy.first] = make_pair(itCopy.second.first-1, floor((quant+1)/(tam+1)) );
                fill += intervals[itCopy.first].second;
            } else {
                quant = ((plays[i]-1) - itCopy.first)+1;
                intervals[itCopy.first] = make_pair(plays[i]-1, floor((quant+1)/(tam+1)) );
                fill += intervals[itCopy.first].second;

                quant = (itCopy.second.first - (plays[i]+1))+1;
                intervals[plays[i]+1] = make_pair(itCopy.second.first,floor((quant+1)/(tam+1)) );
                fill += intervals[plays[i]+1].second;
            }               
        }
        if( fill < k ) break;
        i++;
    } 

    //for( it=intervals.begin(); it!=intervals.end(); ++it ) {
    //    cout << it->first << " " << it->second.first << " " << it->second.second << endl;
    //}
    

    if( i==m ) printf("-1\n");
    else printf("%lld\n",i+1);

    return 0;
}
