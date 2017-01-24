#include <bits/stdc++.h> 

using namespace std;

int main() {
    
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    long long int n, x, a, b, i, cont=0, direcao = 1;
    
    set<long long int> fr;
    set<long long int> ba; 
    set<long long int>::iterator it;

    bool valido = true;

    cin >> n >> x;

    for( i=0; i<n; i++ ) {
        cin >> a >> b;    
        if( b ) fr.insert(a);
        else ba.insert(-a);
    }

    while( valido ) {
        if( direcao ) {
            it = ba.upper_bound(-x);
            if( it!=ba.end() ) {
                x = -*it;
                ba.erase(it);        
            } else {
                x = 0;
                cont++;
            }
            direcao = 0; 
        } else {
            it = fr.upper_bound(x);
            if( it!=fr.end() ) {
                x = *it;
                fr.erase(it);
            } else {
                valido = false;
            }
            direcao = 1; 
        }
    }
    
    if( fr.size() == 0 && ba.size() == 0 ) {
        cout << cont << endl;
    } else { 
        cout << -1 << endl;
    }
    return 0;
}
