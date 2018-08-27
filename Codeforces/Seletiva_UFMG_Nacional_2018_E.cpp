#include <bits/stdc++.h>

using namespace std;

typedef int ll;

vector<ll> vetor;
ll n;

pair<ll,ll> makePlay() {
    pair<ll,ll> resp;
    
    ll actualxor=0, i, qtstiro; 

    for( i=0; i<n; i++ ) {
        actualxor ^= vetor[i];
    }

    for( i=0; i<n; i++ ) {
        qtstiro = vetor[i] - (actualxor^vetor[i]);
        if( qtstiro > 0 ) {
            resp.first = i;
            resp.second = qtstiro;
            return resp;
        }
    }

    resp.first = -1;
    resp.second = -1;
    return resp; 
}


int main() {
    ios_base::sync_with_stdio(false);

    ll i, pos, qtd;

    pair<ll,ll> jogada;

    cin >> n;
    vetor.resize(n);

    for( i=0; i<n; i++ ) {
        cin >> vetor[i];
    }

    jogada = makePlay();
    cout << jogada.first << " " << jogada.second << endl;
    vetor[jogada.first] -= jogada.second;
    
    while( true ) {
        cin >> pos >> qtd;
        if( pos==-1 and qtd==-1 ) break;
        vetor[pos] -= qtd;
        jogada = makePlay();
        cout << jogada.first << " " << jogada.second << endl;          
        vetor[jogada.first] -= jogada.second;
    }

    return 0;
}
