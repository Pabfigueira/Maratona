#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

ll c1, c2, x, y;

bool solve(ll value) {
    ll blockOne, blockTwo, blockBoth;
    blockOne  = value/x;
    blockTwo  = value/y;
    blockBoth = value/(x*y);     

    value -= blockBoth;
    blockOne -= blockBoth;
    blockTwo -= blockBoth;

    if(c1+c2>value) return false;
    if(c1 > value-blockOne) return false;
    if(c2 > value-blockTwo) return false;
    return true;
}

ll bb(ll left, ll right) {
    if(left==right) return left;

    ll mid =  (left+right)/2;
    if(solve(mid)) return bb(left,mid);
    return bb(mid+1,right);
}

int main() {
    scanf("%lld%lld%lld%lld",&c1,&c2,&x,&y);
    if(c1 < c2) {
        swap(c1,c2);
        swap(x,y);
    }
    
    printf("%lld\n",bb(1,1e10));
    return 0;
}
