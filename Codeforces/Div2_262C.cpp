#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
ll n, m, w;
vector<ll> arr;

bool solve(ll mid) {
    ll i, sumAcc, used;
    vector<ll> newArr(n,0);
    for(i=0; i<n; i++) {
        if(mid>arr[i]) {
            newArr[i] = mid-arr[i];
        }
    }
    queue<pair<ll,ll>> accumulate;
    i=sumAcc=used=0; 
    while(i<n) {
        if(newArr[i]!=0) {
            while(accumulate.size()>0 and accumulate.front().first<i) {
                sumAcc -= accumulate.front().second;
                accumulate.pop();
            } 
            newArr[i] -= sumAcc;
            if(newArr[i] > 0) {
                used += newArr[i];
                if(used>m) return false;
                sumAcc += newArr[i];
                accumulate.push(make_pair(i+w-1,newArr[i]));
            } 
        }
        i++;
    }
    return used<=m;
}

ll bb(ll left, ll right) {
    if(left==right) return left;

    ll mid = 1+left+(right-left)/2;
    if(solve(mid))  return bb(mid,right);
    return bb(left,mid-1);
}

int main() {
    ll mini, i;
    scanf("%lld%lld%lld",&n,&m,&w);
    arr.resize(n);
    mini = numeric_limits<ll>::max();
    for(i=0; i<n; i++) {
        scanf("%lld",&arr[i]);
        mini = min(mini,arr[i]);
    }
    printf("%lld\n",bb(mini,100000*1000000000ll)); 

    return 0;
}
