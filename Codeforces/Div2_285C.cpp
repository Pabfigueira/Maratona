#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ll n, i, next, neigh;
    scanf("%lld",&n);

    queue<ll> toRemove;
    vector<ll> xorSum(n);
    vector<ll> degree(n);
    vector<pair<ll,ll>> edges;

    for(i=0; i<n; i++) {
        scanf("%lld%lld",&degree[i],&xorSum[i]);
        if(degree[i]==1) toRemove.push(i);
    }
    
    while(!toRemove.empty()) {
        next = toRemove.front();
        toRemove.pop();
   
        if(degree[next]==0) continue;
 
        degree[next]--;    
        neigh = xorSum[next];
        edges.push_back(make_pair(next,neigh));          
        xorSum[neigh]^=next;
        degree[neigh]--;
        if(degree[neigh]==1) toRemove.push(neigh);
    }
    cout << edges.size() << endl;
    for(i=0; i<(ll)edges.size(); i++) {
        cout << edges[i].first << " " << edges[i].second << endl;
    }
    return 0;
}
