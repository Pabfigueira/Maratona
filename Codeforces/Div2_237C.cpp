#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {

    ll n, k, maxi, i, j, number;
    scanf("%lld%lld",&n,&k);

    map<ll,vector<ll>> mapa;
    vector<ll> freeEdges(n,k);
    vector<pair<ll,ll>> ans;

    maxi = -1;
    for(i=0; i<n; i++) {
        scanf("%lld",&number);
        maxi = max(maxi,number);
        mapa[number].push_back(i);
    }
    if(mapa[0].size()!=1) {
        printf("-1\n");
        return 0;
    }    
 
    for(i=1; i<=maxi; i++) {
        if(mapa[i].size()==0) {
            printf("-1\n");
            return 0;
        } 
        k=0;
        for(j=0; j<(ll)mapa[i].size(); j++) {
            while(k<(ll)mapa[i-1].size() and freeEdges[mapa[i-1][k]]==0) {
                k++;
            }    
            if(k==(ll)mapa[i-1].size()) {
                printf("-1\n");
                return 0;
            }
            ans.push_back(make_pair(mapa[i-1][k],mapa[i][j]));
            freeEdges[mapa[i][j]]--;
            freeEdges[mapa[i-1][k]]--;
        }
    }
    printf("%lld\n",(ll)ans.size());
    for(i=0; i<(ll)ans.size(); i++) {
        printf("%lld %lld\n",ans[i].first+1,ans[i].second+1);
    }

    return 0;
}
