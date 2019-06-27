#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    
    ll n, a, b, bestArea, i, actualA, actualB, bInitial;
    bool swapDone = false;
    scanf("%lld%lld%lld",&n,&a,&b);
    if(a*b < 6*n) {
        if(a>b) {
            swap(a,b);
            swapDone = true;
        }
        i=a;
        bInitial = b;
        bestArea = numeric_limits<ll>::max();
        for(; i<=ceil(sqrt(6*n)); i++) {
            actualA = i;
            actualB = max(bInitial,(ll)ceil((6*n)/(double)i));
            if(bestArea > actualA*actualB) {
                bestArea = actualA*actualB;
                if(swapDone) {
                    b = actualA;
                    a = actualB;    
                } else {
                    a = actualA;
                    b = actualB;
                }
            }
        }
    
    }
    printf("%lld\n%lld %lld\n",a*b,a,b);
    return 0;
}
