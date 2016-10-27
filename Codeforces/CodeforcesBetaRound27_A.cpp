#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    int i, n, num;
    set<int> group;
    for( i=1; i<=3001; i++ ) {
        group.insert(i);
    }
    cin >> n;

    for( i=0; i<n; i++ ) {
        cin >> num;
        group.erase(num);
    }    
    cout << *group.begin() << endl;
    return 0;
}
