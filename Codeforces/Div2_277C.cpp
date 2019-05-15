#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

ll transform(char a, char b) {
    if(a==b) return 0;
    if(a>b) return transform(b,a);
    ll valB, valA, valZ;
    valA = a-'a';
    valB = b-'a';
    valZ = 'z'-'a';
    return min(valB-valA,valZ-valB+valA+1);
}

int main() {
    ll n, p, i, j, cost;
    string word;
    ios_base::sync_with_stdio(false);
    set<ll> toChange;
    set<ll>::iterator maxi, mini;

    cin >> n >> p;
    cin >> word;
    p--;

    i=0; j=n-1;
    while(i<j) {
        if(word[i]!=word[j]) {
            if(p<(n+1)/2) toChange.insert(i);
            else toChange.insert(j);
        }
        i++; j--;
    }
    cost = 0;
    if(toChange.size()==0) {
        cout << cost << endl;
        return 0;
    }
     
    mini = toChange.begin();
    maxi = toChange.end(); maxi--;
    
    cost += *maxi-*mini + min(abs(p-*mini),abs(*maxi-p)); 

    for(maxi=toChange.begin(); maxi!=toChange.end(); ++maxi) {
        cost += transform(word[*maxi],word[(n-1)-*maxi]);
    }

    cout << cost << endl;
    return 0;
}
