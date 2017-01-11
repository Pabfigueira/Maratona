#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    int n, d, i;
    char novo;
    list<char>lista;
    list<char>::iterator it, ita;
    while( cin >> n >> d && (n||d) ) {
        lista.clear();
        for( i=0; i<n; i++ ) {
            cin >> novo;
            if( d==0 ) {
                lista.push_back(novo);
            } else {
                while( d>0 && lista.size()>0 && lista.back()<novo ) {
                    lista.pop_back();
                    d--;
                }
                lista.push_back(novo); 
            }
        }

        while( d>0 ) {
            d--;
            lista.pop_back();
        }
        
        for( it=lista.begin();it!=lista.end();++it ) {
            cout << *it;    
        }
        cout << endl;
    }
    return 0;
}
