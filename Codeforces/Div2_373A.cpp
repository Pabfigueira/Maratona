#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n, i, num, ant;
    cin >> n;
    
    cin >> ant;
    if( n==1 ) {
        if( ant==0 ) cout << "UP\n";
        else if( ant==15 ) cout << "DOWN\n";
        else cout << "-1\n";
    } else {
        int pos = 0;
        bool error = false;

        for( i=1; i<n; i++ ) {
            cin >> num;    
            if( num == ant-1 ) pos = -1;
            else if( num == ant+1 ) pos = 1;
            else {
                error = true;
            } 
            ant = num;
        }

        if( error ) {
            cout << -1 << '\n';
        } else if( (pos==1 && num!=15)  || (pos==-1 && num==0) ) {
            cout << "UP\n";
        } else {
            cout << "DOWN\n";
        }
    }
    return 0;
}
