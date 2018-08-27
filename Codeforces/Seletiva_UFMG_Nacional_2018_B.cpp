#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main() {

    ll t, n, i, a, b, c, time;

    scanf("%lld %lld",&t,&n);
    
    time = 0;

    for( i=0; i<n; i++ ) {
        scanf("%lld %lld %lld",&a,&b,&c);
        if( a <= t ) {
            if( a <= time ) {
                time += c;
            } else {
                time = a+c;
            }   
        } else if( b==1 and a<=time ) {
            time += c;
        }
    }

    printf("%lld\n",max(time,t));

    return 0;
}
