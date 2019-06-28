#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ll n, k, even, odd, i, num, j;
    vector<vector<ll>> ansOdd;
    vector<vector<ll>> ansEven;

    scanf("%lld%lld%lld",&n,&k,&even);
    odd = k-even;
    queue<ll> odds;
    queue<ll> evens;

    for(i=0; i<n; i++) {
        scanf("%lld",&num);
        if(num%2==0) evens.push(num);
        else odds.push(num);    
    }
    
    while(true) {
        if(odd==0) break;
        if((ll)odds.size()==0) {
            printf("NO\n");
            return 0;
        }
        vector<ll> aux;
        aux.push_back(odds.front());
        odds.pop();
        ansOdd.push_back(aux);
        odd--;
    }
    if(odds.size()%2!=0) {
        printf("NO\n");
        return 0;
    }
    while(true) {
        if(even==0) break;
        if((ll)evens.size()>0) {
            vector<ll>aux;
            aux.push_back(evens.front());
            evens.pop();
            ansEven.push_back(aux);
        } else {
            if((ll)odds.size()==0) { 
                printf("NO\n");
                return 0;
            }
            vector<ll> aux;
            aux.push_back(odds.front());
            odds.pop();
            aux.push_back(odds.front());
            odds.pop();
            ansEven.push_back(aux);
        }
        even--;
    }

    if(ansOdd.size()>0) {
        while(!evens.empty()) {
            ansOdd[0].push_back(evens.front());
            evens.pop();
        }
        while(!odds.empty()) {
            ansOdd[0].push_back(odds.front());
            odds.pop();
        }
    } else {
        while(!evens.empty()) {
            ansEven[0].push_back(evens.front());
            evens.pop();
        }
        while(!odds.empty()) {
            ansEven[0].push_back(odds.front());
            odds.pop();
        }
    }
        
    
    printf("YES\n"); 
    for(i=0; i<(ll)ansOdd.size(); i++) {
        printf("%lld",(ll)ansOdd[i].size());
        for(j=0; j<(ll)ansOdd[i].size(); j++) {
            printf(" %lld",ansOdd[i][j]);
        }         
        printf("\n");
    }
    for(i=0; i<(ll)ansEven.size(); i++) {
        printf("%lld",(ll)ansEven[i].size());
        for(j=0; j<(ll)ansEven[i].size(); j++) {
            printf(" %lld",ansEven[i][j]);
        }         
        printf("\n");
    }

    return 0;
}
