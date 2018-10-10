#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main() {

    ll n, i, atual, energy, soma;

    scanf("%lld",&n);

    vector<ll> vetor(n);

    for( i=0; i<n; i++ ) {
        scanf("%lld",&vetor[i]);
    }

    atual = energy = soma = 0;

    for( i=0; i<n; i++ ) {
        energy += (atual-vetor[i]);
        if( energy < 0 ) {
            soma += (-energy);
            energy = 0;
        }
        atual = vetor[i];
    }
    printf("%lld\n",soma);
    return 0;
}
