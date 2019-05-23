#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    ll k, i, ans, sum;
    map<ll,ll> cnt;
    cnt[0]=1;

    string word;
    cin >> k;
    cin >> word;

    ans = sum = 0;
    for(i=0; i<(ll)word.size(); i++) {
        sum += word[i]-'0';
        ans += cnt[sum-k];
        cnt[sum]++; 
    }    
    cout << ans << endl;
    return 0;
}
