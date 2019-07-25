#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

ll mylog2(ll number) {
    return log(number)/log(2);
}

ll solve(ll l, ll r) {
    if(l==r) return 0;
    ll res = mylog2(r);

    if(res==mylog2(l)) {
        return solve(l-(1ll<<res),r-(1ll<<res));
    }
    return (1ll<<(res+1))-1;
}

int main() {
    ll l, r;
    scanf("%lld%lld",&l,&r); 
    printf("%lld\n",solve(l,r)); 
    return 0;
}
