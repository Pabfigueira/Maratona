#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    int t, a;

    long int equipes, jogos, janelas, i, soma, j;
    
    string team;

    map< long int, long int > mapa;
    map< long int, long int >::iterator it;
    vector<long int> vetor;

    vector< pair<long int, string> > champ;

    cin >> t;

    for( a=0; a<t; a++ ) {
        cin >> equipes >> jogos >> janelas;

        champ.clear();
        
        for( j=0; j<equipes; j++ ) {

            soma = 0;
            mapa.clear();
            vetor.clear();
            vetor.resize(jogos);
 
            cin >> team;    
    
            for( i=0; i<jogos; i++ ) {
                cin >> vetor[i];
                mapa[vetor[i]]++;

                if( i >= janelas-1 ) {
                    it = mapa.end();
                    it--;
                    
                    soma += mapa.begin()->first + it->first;

            
                    mapa[ vetor[i-(janelas-1)] ]--;
                    if( mapa[ vetor[i-(janelas-1)] ] == 0 ) {
                        mapa.erase( vetor[i-(janelas-1)] );
                    }
                }         
            }
            champ.push_back( make_pair(soma*(-1), team ) );
        }
        sort(champ.begin(),champ.end());

        cout << champ[0].second << " " << champ[0].first*(-1) << '\n';
    } 

    return 0;
}

