#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;

typedef long long ll;

int main() {
    ll n, m, res, i, j;
    char letter;
    scanf("%lld%lld",&n,&m);
    vector<set<char>> group(m);
    for(i=0; i<n; i++) {
        scanf("%c",&letter);
        for(j=0; j<m; j++) {
            scanf("%c",&letter);
            group[j].insert(letter);
        }    
    }
    res = 1;
    for(i=0; i<m; i++) {
        res = (res*group[i].size())%MOD;
    }
    printf("%lld\n",res);
    return 0;
}
