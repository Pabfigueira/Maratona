#include <bits/stdc++.h> 

using namespace std;

int main() {
    
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    long long int n, d, i, a, b;
    map< long long int, long long int > mapa;
    map< long long int, long long int >::iterator it, pos, ant;

    cin >> n >> d;

    for( i=0; i<n; i++ ) {
        cin >> a >> b;
        mapa[a] += b;  
    }
    mapa[-1] = 0;

    i = 0;

    ant = mapa.begin();
    it = mapa.begin();
    it++;
    for( ; it!=mapa.end();++it,++ant ) {
        it->second += ant->second;
    }

    for( it=mapa.begin(); it!= mapa.end(); ++it ) {
        ant = it;
        ant--;
        
        pos = mapa.lower_bound(it->first+d);
        pos--;

        i = max(i,pos->second-ant->second);
    }
    cout << i << '\n';
    return 0;
}
