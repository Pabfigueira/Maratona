#include<bits/stdc++.h>

using namespace std;

int main() {
    int m, t, r, i, j, remaining, ans;
    priority_queue<int,vector<int>,greater<int>> burning;
    scanf("%d%d%d",&m,&t,&r);
    vector<int> candles(m);
    for(i=0; i<m; i++) {
        scanf("%d",&candles[i]);
    }
    i=ans=0;
    while(i<m) {
        while(burning.size()>0 and burning.top()<candles[i]) {
            burning.pop();    
        }
        remaining = r-burning.size();
        if(remaining>0) {
            if(remaining > t) {
                printf("-1\n");
                return 0;
            }
            for(j=remaining; j>0; j--) {
                burning.push(candles[i]-j+t);
                ans++;    
            } 
        }
        i++;
    } 
    printf("%d\n",ans);
    return 0 ;
}
