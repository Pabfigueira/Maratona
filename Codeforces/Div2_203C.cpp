#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {

    ll n, i, x, y, dist, aux;
    
    priority_queue<pair<ll,pair<ll,ll>>, vector<pair<ll,pair<ll,ll>>>, greater<pair<ll,pair<ll,ll>>>> myQueue;
    pair<ll,pair<ll,ll>> next;

    scanf("%lld",&n);    
    dist = 0;

    for(i=0; i<n; i++) {
        scanf("%lld%lld,",&x,&y);
        aux = abs(x) + abs(y);
        dist += 2;
        if(abs(x)>0) dist+=2;
        if(abs(y)>0) dist+=2;
        myQueue.push(make_pair(aux,make_pair(x,y)));
    }
    printf("%lld\n",dist);
    while(!myQueue.empty()) {
        next = myQueue.top();
        myQueue.pop();
        if(next.second.first>0) {
            printf("1 %lld R\n",next.second.first);
        } else if(next.second.first<0) {
            printf("1 %lld L\n",-next.second.first);
        }
        if(next.second.second>0) {
            printf("1 %lld U\n",next.second.second);
        } else if(next.second.second<0) {
            printf("1 %lld D\n",-next.second.second);
        }
        printf("2\n");
        if(next.second.first>0) {
            printf("1 %lld L\n",next.second.first);
        } else if(next.second.first<0) {
            printf("1 %lld R\n",-next.second.first);
        }
        if(next.second.second>0) {
            printf("1 %lld D\n",next.second.second);
        } else if(next.second.second<0) {
            printf("1 %lld U\n",-next.second.second);
        }
        printf("3\n");      
    }
    return 0;
}
