#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main() {

    ll teste, money, ing, cake, h, maximo, i, qt, soma;

    ll index, qtd, j;

    scanf("%lld",&teste);

    for( h=0; h<teste; h++ ) {
        scanf("%lld%lld%lld",&money,&ing,&cake);

        vector<ll> ingred(ing);

        for( i=0; i<ing; i++ ) {
            scanf("%lld",&ingred[i]);
        }
        
        maximo = 0;

        for( i=0; i<cake; i++ ) {
            soma = 0;
            scanf("%lld",&qt); 
            for( j=0; j<qt; j++ ) {
                scanf("%lld%lld",&index,&qtd);
                soma += (qtd * ingred[index]);
            }
            maximo = max(maximo,money/soma);
        }
        printf("%lld\n",maximo);     
    } 

    return 0;
}
