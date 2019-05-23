#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ll n, i, prefixSum, totalDiff;
    scanf("%lld",&n);

    vector<ll> arr(n);

    for(i=0; i<n; i++) {
        scanf("%lld",&arr[i]);
    }
    sort(arr.begin(),arr.end());
    totalDiff = 0;
    prefixSum = arr[0];
    for(i=1; i<n; i++) {
        totalDiff += (arr[i]*i) - prefixSum;
        prefixSum += arr[i];
    }
    prefixSum += 2*totalDiff;
    printf("%lld %lld\n",prefixSum/__gcd(prefixSum,n),n/__gcd(prefixSum,n));
    return 0;
}
