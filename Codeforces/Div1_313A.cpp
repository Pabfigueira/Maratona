#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

ll eleva( ll num ) {
    return num*num;
}

int main() {
    
    vector<ll> vetor(6);
    
    for( ll i=0; i<6; i++ ) {
        scanf("%lld",&vetor[i]);
    }
    
    printf("%lld\n",eleva(vetor[0]+vetor[1]+vetor[2]) - eleva(vetor[0]) - eleva(vetor[2]) - eleva(vetor[4]));

    return 0;
}
