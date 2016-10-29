#include <bits/stdc++.h> 

using namespace std;

int main() {
    
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    string word;
    int i, qt, tam;

    qt = 0;
    
    map<char,int> mapa;

    getline(cin,word);
    tam = word.size();

    for( i=0; i<tam; i++ ) {
        mapa[word[i]]++;
        if( mapa[word[i]]%2==0 ) qt--;
        else qt++;
    }

    if( qt==0 || qt%2!=0) cout << "First\n";
    else cout << "Second\n";

    return 0;
}
