#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

ll n, k;
string newWord;

ll solve(string word, ll digit) {
    ll cnt, i, cost, diff;
    cnt = cost = 0;
    priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> less;
    priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> greater;
    for(i=0; i<n; i++) {
        diff = (word[i]-'0') - digit;
        if(diff==0) cnt++;
        else if(diff<0) less.push(make_pair(abs(diff),-i));
        else greater.push(make_pair(abs(diff),i));
    }
    if(cnt>=k) {
        newWord = word;
        return 0;
    }
    
    while(cnt<k) {
        if(less.empty()) {
            cost += greater.top().first;
            word[greater.top().second] = digit+'0';
            greater.pop();    
        } else if(greater.empty()) {
            cost += less.top().first;
            word[-less.top().second] = digit+'0';
            less.pop();
        } else {
            if(less.top().first < greater.top().first) {
                cost += less.top().first;
                word[-less.top().second] = digit+'0';
                less.pop(); 
            } else {    
                cost += greater.top().first;
                word[greater.top().second] = digit+'0';
                greater.pop();
            } 
        }
        cnt++;       
    }
    newWord = word;
    return cost;
}


int main() {
    ios_base::sync_with_stdio(false);
    string word, ans;
    ll minimum, i, cost; 
    minimum = numeric_limits<ll>::max();
    cin >> n >> k >> word;
    for(i=0; i<=9; i++) {
        cost = solve(word,i);   
        if(cost < minimum or (cost==minimum and newWord<ans)) {
            minimum = cost;
            ans = newWord;        
        } 
    }
    cout << minimum << endl << ans << endl;
    return 0;
}
