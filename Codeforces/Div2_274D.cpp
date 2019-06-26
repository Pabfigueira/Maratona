#include<bits/stdc++.h>

using namespace std;

typedef long long ll;


bool attend(ll value, set<ll> marks) {
    set<ll>::iterator it;
    for(it=marks.begin(); it!=marks.end(); ++it) {
        if(marks.find(*it+value)!=marks.end() or marks.find(*it-value)!=marks.end()) 
            return true;
    }
    return false;
}

ll uniqueMark(ll x, ll y, ll n, set<ll> marks) {
    set<ll>::iterator it;
    ll z;
    // (*it = z+x) or (*it = z-x)
    for(it=marks.begin(); it!=marks.end(); ++it) {
        z = *it-x;
        if(z>=0) {
            if(marks.find(z+y)!=marks.end() or marks.find(z-y)!=marks.end() or z==y) {
                return z;
            }    
        }
        z = *it+x;
        if(z<=n) {
            if(marks.find(z+y)!=marks.end() or marks.find(z-y)!=marks.end() or z==y) {
                return z;
            }
        }
    }
    return -1;      
}

int main() {    
    ll n, l, x, y, num, i;
    set<ll> marks;
    set<ll>::iterator it;

    scanf("%lld%lld%lld%lld",&n,&l,&x,&y);
    for(i=0; i<n; i++) {
        scanf("%lld",&num); 
        marks.insert(num);
    }
    if(attend(x,marks)) {
        if(attend(y,marks)) {
            printf("0\n"); 
        } else {
            printf("1\n%lld\n",y);    
        }
    } else {
        if(attend(y,marks)) {
            printf("1\n%lld\n",x);
        } else {
            num = uniqueMark(x,y,l,marks); 
            if(num!=-1) printf("1\n%lld\n",num);
            else printf("2\n%lld %lld\n",x,y);
        }
    }
    return 0;
}
