#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<vector<pair<ll,ll>>> graph;
set<ll> ans;

ll dfs(ll actual, ll dad, ll edgeDad) {
    if((actual!=0 or dad!=0) and (ll)graph[actual].size()==1) {
        if(edgeDad==2) {
            ans.insert(actual+1);
            return actual+1;
        }
        return -1;
    }
    ll next = -1;
    for(ll i=0; i<(ll)graph[actual].size(); i++) {
        if(graph[actual][i].first!=dad) {
            next = max(next,dfs(graph[actual][i].first,actual,graph[actual][i].second));
        }
    }
    if(next==-1 and edgeDad==2) {
        ans.insert(actual+1);
        return actual+1;
    }
    return next;
}

int main() {

    ll n, i, x, y, t;

    scanf("%lld",&n);
    graph.resize(n);

    for(i=0; i<n-1; i++) {
        scanf("%lld%lld%lld",&x,&y,&t);
        x--; y--;
        graph[x].push_back(make_pair(y,t));
        graph[y].push_back(make_pair(x,t));
    }

    set<ll>::iterator it;
    dfs(0,0,-1);

    printf("%lld\n",(ll)ans.size());
    for(it=ans.begin(); it!=ans.end(); ++it) {
        if(it!=ans.begin()) printf(" ");
        printf("%lld",*it);    
    }
    printf("\n");
    return 0;
}
