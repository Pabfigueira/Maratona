#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main() {
    ll n, i, number, seq, maximo, ant;

    maximo = 0;
    seq = 0;

    scanf("%lld",&n);

    ant = -1;

    for( i=0; i<n; i++ ) {
        scanf("%lld",&number);    
        if( number >= ant ) seq++;
        else {
            maximo = max(maximo,seq);
            seq = 1;
        }
        ant = number;
    }
    maximo = max(maximo,seq);
    printf("%lld\n",maximo);
    return 0;
}
