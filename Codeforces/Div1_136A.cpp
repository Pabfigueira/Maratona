#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main() {

    ll n, i, swap;

    scanf("%lld",&n);

    vector<ll> vetor(n);
    vector<ll> sorted(n);

    for( i=0; i<n; i++ ) {
        scanf("%lld",&vetor[i]);
        sorted[i] = vetor[i];
    }

    sort(sorted.begin(),sorted.end());

    swap = 0;
    for( i=0; i<n; i++ ) {
        if( sorted[i]!=vetor[i] ) swap++;
    }
    if( swap<=2 ) printf("YES\n");
    else printf("NO\n");
    return 0;
}
