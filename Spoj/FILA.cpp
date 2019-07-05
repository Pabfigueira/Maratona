#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> gaps;

vector<pair<pair<ll,ll>,ll>> solve(vector<pair<pair<ll,ll>,ll>> arr, ll k) {
    if((ll)arr.size() <= k) return arr;

    ll i;
    pair<ll,ll> topo;
    vector<pair<pair<ll,ll>,ll>> aux; 
    
    topo = gaps.top();
    gaps.pop();

    i=1;
    while(i<(ll)arr.size()) {
        if(arr[i].first.second==topo.second) {
            aux.push_back(make_pair(arr[i-1].first,arr[i].second));
            i+=2;
        } else {
            aux.push_back(arr[i-1]);        
            i++;
        }
    } 
    if(topo.second != arr[arr.size()-1].first.second) {
        aux.push_back(arr[arr.size()-1]);
    }
    return solve(aux,k); 
}


int main() {

    ll n, k, i, ans;
    vector<pair<pair<ll,ll>,ll>> arr;
    vector<pair<pair<ll,ll>,ll>> sol;
    while(scanf("%lld%lld",&n,&k)!=EOF) {
        arr.clear();
        arr.resize(n);
        arr[0].first.first = arr[0].first.second = arr[0].second = 0;
        while(!gaps.empty()) {
            gaps.pop();
        }
        for(i=1; i<n; i++) {
            scanf("%lld",&arr[i].first.first);
            arr[i].first.second = i;
            arr[i].second = arr[i].first.first;
            gaps.push(make_pair(arr[i].first.first-arr[i-1].first.first,i));
        }
        ans = 0;
        sol = solve(arr, k);
        for(i=0; i<(ll)sol.size(); i++) { 
            ans += sol[i].second - sol[i].first.first;     
        }
        printf("%lld\n",ans);
    }
    return 0;
}
