#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int s, a, n, ant, contador, maximo, i;
    cin >> s;

    vector<int> vetor;

    for( a=0; a<s; a++ ) {
        cin >> n;
        
        vetor.clear();
        vetor.resize(n);        

        ant = 0;
        contador = 0;
        maximo = 0;

        for( i=0; i<n; i++ ) {
            cin >> vetor[i];
            contador+=vetor[i];
            if( contador == 42 ) {
                ant = i+1;
                contador = 0;
                maximo++;
            } else if( contador > 42 ) {
                while( contador > 42 ) {
                    contador -= vetor[ant];
                    ant++;
                }
                if( contador == 42  ){
                    ant = i+1;
                    contador = 0;
                    maximo++;
                }   
            }            
        }
        
        cout << maximo << "\n";    
    }    
    
    return 0;
}
