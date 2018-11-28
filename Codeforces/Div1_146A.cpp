#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main() {

    ll n;

    scanf("%lld",&n);
    
    if( n==1 ) printf("1\n");
    else if( n==2 ) printf("2\n");
    else if( n==3 ) printf("6\n");
    else if( n%2==1) printf("%lld\n",n*(n-1)*(n-2));
    else {
        if( n%6==0 ) printf("%lld\n",(n-1)*(n-2)*(n-3));
        else printf("%lld\n",n*(n-1)*(n-3));
    } 
    return 0;
}
