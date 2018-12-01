#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);

    ll n, m, i, pos, contador, aux;
    char letter;

    cin >> n >> m;

    vector<char> vetor(n);

    for( i=0; i<n; i++ ) {
        cin >> vetor[i];
    }    

    contador = 0;
    for( i=0; i<n-1; i++ ) {
        if( vetor[i]=='.' ) {
            if( vetor[i+1]=='.' ) contador++;
        }
    }
    
    for( i=0; i<m; i++ ) {
        cin >> pos >> letter;
        pos--;
        if( letter == '.' and vetor[pos] != '.' ) {
            aux = 0;
            if( pos>0 and vetor[pos-1]=='.' ) aux++;
            if( pos<n-1 and vetor[pos+1]=='.' ) aux++;
            contador += aux;      
        }
        if( letter != '.' and vetor[pos] == '.' ) {
            aux = 0;
            if( pos>0 and vetor[pos-1]=='.' ) aux++;
            if( pos<n-1 and vetor[pos+1]=='.') aux++;
            contador -= aux;
        }   
        vetor[pos] = letter;     
        cout << contador << endl;
    }
    

    return 0;
}
