#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    long int n, i, qtr1, qtb1, qtr2, qtb2;
    char rb, br, c;

    rb = 'r';
    br = 'b'; 

    qtb1 = 0;
    qtb2 = 0;
    qtr1 = 0;
    qtr2 = 0;

    cin >> n;
    
    for( i=0; i<n; i++ ) {
        cin >> c;

        if( c!=rb  && rb=='r' ) qtr1++;
        if( c!=rb  && rb=='b' ) qtb1++;

        if( c!=br  && br=='r' ) qtr2++;
        if( c!=br  && br=='b' ) qtb2++;  
        

        if( rb=='r' ) rb='b';
        else rb = 'r';

        if( br=='r' ) br='b';
        else br='r'; 
    }

    cout << min( max(qtr1,qtb1) , max(qtr2,qtb2) ) << '\n';
    return 0;
}
