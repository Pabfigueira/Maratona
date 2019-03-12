#include<bits/stdc++.h>
typedef long long int ll;

using namespace std;

int main() {
    ll n, m, i, left, right;

    scanf("%lld%lld",&n,&m);
    vector<ll> numbers(n);
    vector<ll> inc(n);
    vector<ll> dec(n);
    vector<ll> pre(n);
    vector<ll> pos(n);

    for(i=0;i<n;i++) {
        scanf("%lld",&numbers[i]);
        if(i==0) {
            inc[i] = 1;
            dec[i] = 1; 
        } else {
            if( numbers[i]==numbers[i-1] ) {
                inc[i] = inc[i-1]+1;
                dec[i] = dec[i-1]+1;
            } else if( numbers[i] > numbers[i-1] ) {
                inc[i] = inc[i-1]+1;
                dec[i] = dec[i-1];
            } else {
                inc[i] = inc[i-1];
                dec[i] = dec[i-1]+1;
            }
        }
    }        
    for(i=n-1;i>=0;i--) {
        if(i==n-1 or inc[i]==inc[i+1]) pre[i] = i;
        else pre[i] = pre[i+1];

        if(i==n-1 or dec[i]==dec[i+1]) pos[i] = i;
        else pos[i] = pos[i+1];
    }
    
    for(i=0;i<m;i++) {
        scanf("%lld%lld",&left,&right);
        left--; right--;
        if( pre[left] >= right ) printf("Yes\n");
        else if( pos[pre[left]]>=right ) printf("Yes\n");
        else printf("No\n");
    } 

      
    return 0;
}
