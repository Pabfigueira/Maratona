#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    
    ll i, ans;
    string word;
    vector<ll> prefix;
    vector<ll> alphabet(26);
    map<char,map<ll,ll>> dp;

    for(i=0; i<26; i++) {
        cin >> alphabet[i];
    }
    cin >> word;

    prefix.resize(word.size(),0);
    for(i=0; i<(ll)word.size(); i++) {
        prefix[i] = alphabet[word[i]-'a'];
        if(i>0) prefix[i] += prefix[i-1];
    }
    
    ans = 0;
    for(i=0; i<(ll)word.size(); i++) {
        ans += dp[word[i]][prefix[i]-alphabet[word[i]-'a']];
        dp[word[i]][prefix[i]]++;
    } 
    
    cout << ans << endl;     
    return 0;
}
