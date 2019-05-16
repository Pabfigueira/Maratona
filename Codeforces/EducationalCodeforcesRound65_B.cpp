#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

ll getCommon(pair<ll,ll> one, pair<ll,ll> two) {
    if(one.first==two.first) return one.first;
    if(one.first==two.second) return one.first;
    if(one.second==two.first) return one.second;
    if(one.second==two.second) return one.second;
    return -1;
}


int main() {
    ll mult1, mult2, mult3, mult4, i;

    set<ll> possible = {4,8,15,16,23,42};
    set<ll>::iterator it, ita;
    map<ll,pair<ll,ll>> mapa;
    
    for(it=possible.begin();it!=possible.end();++it) {
        ita=it; ita++;
        for(;ita!=possible.end();++ita) {
            mapa[*it * *ita] = make_pair(*it,*ita); 
        }
    }

    vector<ll> ans(6);
    
    cout << "? 1 2" << endl;
    cin >> mult1;
    cout << "? 1 3" << endl;
    cin >> mult2;
    cout << "? 4 5" << endl;
    cin >> mult3;
    cout << "? 4 6" << endl;
    cin >> mult4;

    ans[0] = getCommon(mapa[mult1],mapa[mult2]);
    ans[1] = mult1/ans[0];
    ans[2] = mult2/ans[0];
 
    ans[3] = getCommon(mapa[mult3],mapa[mult4]);
    ans[4] = mult3/ans[3];
    ans[5] = mult4/ans[3];
     
    cout << "!";
    for(i=0; i<6; i++) {
        cout << " " << ans[i];    
    }
    cout << endl;
    return 0;
}
