#include <bits/stdc++.h> 

using namespace std;

map<string, set<string> > graph;
set<string> visited;
list< pair<string,int> > fila;

void busca() {
    
    set<string>::iterator it;
    string people = fila.front().first;
    int g = fila.front().second;
    
    fila.pop_front();

    if( people!="Rerisson" ){
        visited.insert(people);
    } 
 
    if( g==0 ) return;

    for( it=graph[people].begin(); it!=graph[people].end(); ++it ) {
        if( *it!="Rerisson" && visited.find(*it)==visited.end() ) {
            fila.push_back( make_pair(*it,g-1) );
        }        
    } 
}


int main() {
    
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    int n, g, i;

    string a, b;

    cin >> n >> g;

    for( i=0; i<n; i++ ) {
        cin >> a >> b;

        graph[a].insert(b);
        graph[b].insert(a);
    }

    fila.push_front( make_pair("Rerisson",g) );
    
    while( !fila.empty() ) {
        busca();
    }
    set<string>::iterator it;
    cout << visited.size() << endl;
    for( it=visited.begin(); it!=visited.end(); ++it ) {
        cout << *it << endl;
    }
    
    return 0;
}
