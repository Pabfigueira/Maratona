#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int t, a, x, y;

    cin >> t;
    
    for( a=0; a<t; a++ ) {
        cin >> x >> y; 

        if( x>y ) cout << ">\n";
        else if( x<y ) cout << "<\n";
        else cout << "=\n";
    }    
    
    return 0;
}
