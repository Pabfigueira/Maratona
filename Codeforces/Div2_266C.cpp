#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main() {
    ll n, i, j, soma;
    
    scanf("%lld",&n);

    vector<ll> vetor(n);
    vector<ll> right(n,0);
    vector<ll> left(n,0);

    for( i=0; i<n; i++ ) {
        scanf("%lld",&vetor[i]);
        if( i>0 ) right[i] = vetor[i] + right[i-1];     
        else right[i] = vetor[i];
        left[i] = vetor[i];
    } 
    for( i=n-2; i>=0; i-- ) {
        left[i] += left[i+1];    
    }     

    if( right[n-1]%3 != 0 ) cout << "0\n";
    else {
        vector<ll> ida;
        vector<ll> volta;

        for( i=0; i<n; i++ ){
            if( right[i]==right[n-1]/3 ) ida.push_back(i);
            if( left[i]==right[n-1]/3 ) volta.push_back(i);
        }
        soma = 0;
        j=0;
        
        for( i=0; i<ida.size(); i++ ) {
            while( j<volta.size() and volta[j]<=(ida[i]+1) ) j++;
            soma += (volta.size() - j);     
        } 
        printf("%lld\n",soma);
    
    }
    
    return 0;
}
