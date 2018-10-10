#include <bits/stdc++.h>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);

    string number;
    int i;
    bool foi = false;

    cin >> number;

    for( i=0; i<number.size(); i++ ) {
        if( !foi and number[i]=='0' ) {
            foi = true;
        } else if( !foi and i==number.size()-1 ) {
            foi = true;
        } else { 
            cout << number[i];
        } 
    }
    cout << endl;
    return 0;
}
