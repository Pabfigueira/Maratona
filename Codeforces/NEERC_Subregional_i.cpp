#include <bits/stdc++.h> 

using namespace std;

int main() {
    
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int x, y, a, b, c, d, e, i;

    pair<int,int> par;

    cin >> x >> y;

    map< pair<int,int>, map<int,int> > groupa;
    
    map<int,int>::iterator it;

    set< pair<int, pair<int, pair<int, pair<int, pair<int, pair<int,int> > > > > > > vetor;  
    set< pair<int, pair<int, pair<int, pair<int, pair<int, pair<int,int> > > > > > >::iterator ita;


    for( i=0; i<x; i++ ) {
        cin >> a >> b >> c >> d;
        groupa[ make_pair(a,b) ][c] = d;
    }       

    for( i=0; i<y; i++ ) {
        cin >> a >> b >> c >> d >> e;
        par = make_pair(a,b);
        
        if( groupa.find( par ) != groupa.end() ) {
            it = groupa[par].lower_bound(d);

            if( it != groupa[par].begin() ){    
                it--;
                vetor.insert( make_pair( it->second , make_pair( a, make_pair( b, make_pair(it->first, make_pair(c, make_pair(d,e) ) ) ) ) ));
            }
        } 
    } 

    cout << vetor.size() << endl;

    for( ita=vetor.begin(); ita!=vetor.end(); ++ita ) {
        cout << ita->second.first << " " << ita->second.second.first << " " << ita->second.second.second.first << " " << ita->first << " ";
        cout << ita->second.second.second.second.first << " " << ita->second.second.second.second.second.first << " " << ita->second.second.second.second.second.second << endl;
    }

    return 0;
}
