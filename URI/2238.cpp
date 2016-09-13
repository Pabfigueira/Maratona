#include <bits/stdc++.h>

using namespace std; 

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    long long int a, b, c, d, i, e;

    cin >> a >> b >> c >> d;
    
    set<int> group;

    for( i=1; i<=sqrt(c); i++ ) {
        if( c%i==0 ) {
            e = c/i;

            if( i%a==0 && i%b!=0 && d%i!=0 ) {
                group.insert(i);
            }

            if( e%a==0 && e%b!=0 && d%e!=0 ) {
                group.insert(e);
            }
        }
    }

    if( group.size()==0 ) {
        cout << -1 << '\n';
    } else {
        cout << *group.begin() << '\n';
    }

    return 0;
}
