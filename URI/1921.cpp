#include <bits/stdc++.h> 

using namespace std;

int main() {
    
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    long long int n, total;
    cin >> n;
    total = (n*(n-3))/2;

    cout << total << endl;
    return 0;
}
