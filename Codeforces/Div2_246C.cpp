#include <bits/stdc++.h>
#define MAX 100106
using namespace std;

typedef long long int ll;

vector<int> isPrime(MAX,1);
set<ll> listOfPrimes;
set<ll>::iterator novo;
vector<ll> vetor;
vector<ll> position;

void crivo() {
    ll multi, exp, i;
    for( i=2; i<=100100; i++ ) {
        if( isPrime[i]==1 ) {
            listOfPrimes.insert(i);
            multi = i*2;
            exp = 3;
            while( multi <= 100100 ) {
                isPrime[multi] = 0;
                multi = i*exp;
                exp++;     
            }     
        }
    }
}


int main() {

    vector< pair<ll,ll> > changes;    

    crivo();

    ll n, i, diferenca, novoIndice, valorNoIndice, indicedoI;

    scanf("%lld",&n);

    vetor.resize(n);
    position.resize(n);

    for( i=0; i<n; i++ ) {
        scanf("%lld",&vetor[i]);
        vetor[i]--;
        position[vetor[i]] = i; 
    }

    for( i=0; i<n; i++ ) {
        while( position[i] != i ) {
            diferenca = position[i] - i;
            if( diferenca>0 ) {
                novo = listOfPrimes.upper_bound(diferenca+1);
                novo--;
                // Getting old Values
                novoIndice = position[i] - (*novo-1);
                valorNoIndice = vetor[novoIndice];
                indicedoI = position[i];
                // Updating values
                position[i] = novoIndice;
                position[valorNoIndice] = indicedoI;
                swap(vetor[novoIndice],vetor[indicedoI]);

                changes.push_back( make_pair(indicedoI+1,novoIndice+1) );
            } else {
                diferenca *= (-1);
                novo = listOfPrimes.upper_bound(diferenca+1);
                novo--;
                // Getting old Values
                novoIndice = position[i] + (*novo-1);
                valorNoIndice = vetor[novoIndice];
                indicedoI = position[i];
                // Updating values
                position[i] = novoIndice;
                position[valorNoIndice] = indicedoI;
                swap(vetor[novoIndice],vetor[indicedoI]);
            
                changes.push_back( make_pair(indicedoI+1,novoIndice+1) );
            }    
        }
    } 
    printf("%lld\n",(ll)changes.size());
    for( i=0; i<(ll)changes.size(); i++ ) {
        printf("%lld %lld\n", min(changes[i].first, changes[i].second), max(changes[i].first, changes[i].second));
    }
    return 0;
}
