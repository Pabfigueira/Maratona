#include <bits/stdc++.h>

using namespace std;

int main() {
    //ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    double h, u, d, f, taxe, snail, day, last;

    bool success, fail;

    while( cin >> h >> u >> d >> f && h  ) {
        
        taxe = u * (f/100.00);

        last = u+taxe;

        snail = 0;

        day = 0;

        success = false;
        fail = false;

        while( !success && !fail ) {
            //cout << snail << endl;
            if( last > taxe  ) {
                snail += last - taxe; 
                last -= taxe;
            
                if( snail > h ) success = true;
            } else {
                last = 0;
            }

            snail -= d;

            if( snail < 0 ) {
                fail = true;
            } 
            day++;
        }

        if( success ) {
            cout << "success ";
        } else {
            cout << "failure ";
        }
        cout << "on day " << day << '\n';
    }    
    return 0;
}