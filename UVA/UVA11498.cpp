#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int t, a, b, i, x, y;

    while( cin >> t && t ) {
        cin >> a >> b;

        for( i=0; i<t; i++ ) {
            cin >> x >> y;

            if( x==a || y==b ) {
                cout << "divisa\n";
            } else if( x>a && y>b ) {
                cout << "NE\n";
            } else if( x>a && y<b ) {
                cout << "SE\n";
            } else if( x<a && y>b ) {
                cout << "NO\n";
            } else {
                cout << "SO\n";
            }
        }
    }    
    
    return 0;
}