#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int t, a, n, i, speed, num;

    cin >> t;

    for( a=0; a<t; a++ ) {
        cin >> n;

        speed = 0;

        for( i=0; i<n; i++ ) {
            cin >> num;
            speed = max(speed,num);        
        }
        cout << "Case " << a+1 << ": " << speed << '\n';
    }   
    
    return 0;
}
