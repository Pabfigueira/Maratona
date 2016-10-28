#include <bits/stdc++.h> 

using namespace std;

int main() {
    
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    string word;
    int size, i, n, a, b;

    getline(cin,word);

    size = word.size();    

    vector<int> dp(size,0);

    for( i=1;i<size;i++ ) {
        if( word[i] == word[i-1] ) dp[i] = dp[i-1]+1;
        else dp[i] = dp[i-1];
    }

    cin >> n;

    for( i=0;i<n;i++ ) {
        cin >> a >> b;

        a--; b--;

        cout << dp[b] - dp[a] << '\n';
    }
    return 0;
}
