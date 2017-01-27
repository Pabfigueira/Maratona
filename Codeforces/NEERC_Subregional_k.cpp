#include <bits/stdc++.h> 

using namespace std;

int main() {
    
    //ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n, m, i, j, x, y, acX, acY, maxX, minX, maxY, minY;

    string option;

    cin >> n >> m;

    acX = 0;
    acY = 0;
    maxX = minX = maxY = minY = 0;

    for( i=1; i<=n; i++ ) {
        for( j=1; j<=m; j++ ) {

            if( i+maxX < 1 || i+maxX > n || i+minX < 1 || i+maxX > n || 
                j+maxY < 1 || j+maxY > m || j+minY < 1 || j+maxY > m ) {
                continue;
            }
    
            x = i+acX;
            y = j+acY;

            cout << x << " " << y << endl;
 
            cin >> option;
            if( option == "DETECTED" ) { 
                return 0;
            }

            if( option.compare("U") == 0 ) {
                acX--;
            } else if( option.compare("D") == 0 ) {
                acX++;
            } else if( option.compare("L") == 0 ) {
                acY--;
            } else if( option.compare("R") == 0 ) {
                acY++;
            }
            maxX = max(maxX, acX); minX = min(minX, acX);
            maxY = max(maxY, acY); minY = min(minY, acY);                        
        }
    }
    return 0;
}
