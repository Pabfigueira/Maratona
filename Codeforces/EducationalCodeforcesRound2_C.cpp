#include <bits/stdc++.h> 

using namespace std;

int main() {
    
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    string word, result;

    long int tam, i;

    map<char,int> mapa;
    map<char,int>::iterator ita;
    set<char> group;
    set<char>::iterator it;
    cin >> word;

    tam = word.size();

    for( i=0; i<tam; i++ ) {
        mapa[ word[i] ]++;
        if( mapa[word[i]]%2==0 ) group.erase( word[i] );
        else group.insert( word[i] );      
    }
    
    if( tam%2 == 0 ) {
        while( !group.empty() ) {
            mapa[*group.begin()]++;
            group.erase( group.begin() );
            it = group.end();
            it--;
            mapa[*it]--;
            group.erase(it);
        }

        for( ita=mapa.begin(); ita!=mapa.end(); ++ita ) { 
            for( i=0; i<ita->second/2; i++ ) {
                result+=ita->first;
            } 
        }
        ita = mapa.end();
        ita--;
        while( ita!=mapa.begin() ) {
            for( i=0;i<ita->second/2; i++ ) {
                result+=ita->first;
            }
            ita--;
        }
        for( i=0; i<ita->second/2; i++ ) {
            result+=ita->first;
        }
        cout << result << "\n";
    } else {
        while( group.size() != 1 ) {
            mapa[*group.begin()]++;
            group.erase( group.begin() );
            it = group.end();
            it--;
            mapa[*it]--;
            group.erase(it);
        }
        
        for( ita=mapa.begin(); ita!=mapa.end(); ++ita ) { 
            for( i=0; i<ita->second/2; i++ ) {
                result+=ita->first;
            } 
        }
        ita = mapa.end();
        ita--;
        result+=*group.begin();
        while( ita!=mapa.begin() ) {
            for( i=0;i<ita->second/2; i++ ) {
                result+=ita->first;
            }
            ita--;
        }
        for( i=0; i<ita->second/2; i++ ) {
            result+=ita->first;
        }
        cout << result << "\n";
    } 

    return 0;
}
