#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<ll> arr;
vector<ll> sum;
ll k;

ll binary_search(ll index, ll left, ll right) {
    if(left==right) return left;
    ll mid = (left+right)/2+1;

    ll res = mid*arr[index];
    if(index>=mid) res -= (sum[index]-sum[index-mid]);
    else res -= sum[index];

    if(res<=k) return binary_search(index,mid,right);
    return binary_search(index,left,mid-1); 
}

int main() {

    ll n, i, ans, num, value, cnt;
    
    scanf("%lld%lld",&n,&k);

    arr.resize(n);
    sum.resize(n);

    for(i=0; i<n; i++) {
      scanf("%lld",&arr[i]);
    } 
    sort(arr.begin(),arr.end());

    if(k==0) {
        ans = 1;
        cnt = 1;
        num = arr[0];
        i=1; 
        while(i<n) {
            while(i<n and arr[i]==arr[i-1]) {
                i++; cnt++;
            }
            if(cnt > ans) {
                ans = cnt;
                num = arr[i-1];
            }
            cnt = 1;
            i++; 
        }
        printf("%lld %lld\n", ans, num);
        return 0;
    }

    for(i=0; i<n; i++) {
      sum[i] = arr[i];
      if(i>0) sum[i] += sum[i-1];    
    }  
    ans=0;
    for(i=0; i<n; i++) {
        value = binary_search(i,1,i+1);
        if(value > ans) {
            ans = value;
            num = arr[i];
        }
    }
    printf("%lld %lld\n", ans, num);
    return 0;
}
