#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int tam, i;

    string word;

    cin >> word;    
    bool t = false;

    tam = word.size();

    for( i=0; i<tam; i++ ) {
        if( word[i] == 'H' || word[i] == 'Q' || word[i]=='9' )
            t = true;
    }
    if( t == true ) cout << "YES\n";
    else cout << "NO\n";

    return 0;
}
