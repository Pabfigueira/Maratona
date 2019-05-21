#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
vector<ll> possibles;
vector<ll> ans;
vector<vector<vector<ll>>> dp(1001,vector<vector<ll>>(11,vector<ll>(11,3)));
ll k;

bool solve(ll index, ll last, ll diff) {
    if(index==k) return true;
    if(diff>10) return false;
    if(dp[index][last][diff]!=3) return dp[index][last][diff];

    vector<ll>::iterator it;
    for(it=upper_bound(possibles.begin(),possibles.end(),diff); it!=possibles.end(); ++it) {
        if(*it!=last and solve(index+1,*it,*it-diff)) {
            dp[index][last][diff] = 1;
            ans[index] = *it;
            return true;
        }
    }   
    dp[index][last][diff] = 0;  
    return false;
}


int main() {
    ios_base::sync_with_stdio(false);
    string word;
    ll i;
    getline(cin,word);
    for(i=0; i<(ll)word.size(); i++) {
        if(word[i]=='1') possibles.push_back(i+1);
    } 
    cin >> k;
    ans.resize(k);
    if(solve(0,0,0)) {
        cout << "YES\n";
        for(i=0; i<k; i++) {
            if(i>0) cout << " ";
            cout << ans[i];
        }
        cout << endl;
    } else {
        cout << "NO\n";
    }
    return 0;
}
