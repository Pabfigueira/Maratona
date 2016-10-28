#include <bits/stdc++.h> 

using namespace std;

int main() {
    
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n, i, j;

    set<int> visited;
    vector<int> values(3);

    cin >> n >> values[0] >> values[1] >> values[2];

    vector<int> dp(n+1,-1);

    sort(values.begin(),values.end());
    
    dp[0] = 0;

    for( i=0; i<3; i++ ) {
        if( visited.find(values[i])==visited.end() ) {
            visited.insert(values[i]);
            for( j=values[i]; j<=n; j++ ) {
                if( dp[j-values[i]] != -1 ) {
                    dp[j] = max( dp[j], dp[j-values[i]]+1 );
                }        
            }
        }
    }
    cout << dp[n] << '\n';  
    return 0;
}
