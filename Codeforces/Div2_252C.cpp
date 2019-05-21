#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

ll n, m;

pair<ll,ll> getNext(ll line, ll column) {
    if(line%2) {
        if(column==m) line++; 
        else column++;  
    } else {
        if(column==1) line++;
        else column--;
    }
    return make_pair(line,column);
}


int main() {
    ll k, total, firstSize, i, j, line, column;
    pair<ll,ll> next;
   
    scanf("%lld%lld%lld",&n,&m,&k);
    vector<vector<pair<ll,ll>>> ans(k);

    total = n*m;
    firstSize = total - (k-1)*2;
       
    line = column = 1;
    for(i=0; i<firstSize; i++) {
        ans[0].push_back(make_pair(line,column));
        next = getNext(line,column);
        line = next.first;
        column = next.second;  
    }

    for(i=1; i<k; i++) {
        ans[i].push_back(make_pair(line,column));
        next = getNext(line,column);
        ans[i].push_back(make_pair(next.first,next.second));
        next = getNext(next.first,next.second);
        line = next.first;
        column = next.second;  
    }
 
    for(i=0; i<k; i++) { 
        printf("%lld",(ll)ans[i].size());
        for(j=0; j<(ll)ans[i].size(); j++) {
            printf(" %lld %lld",ans[i][j].first,ans[i][j].second);
        }    
        printf("\n");
    } 
    return 0;
}
