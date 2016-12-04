#include <bits/stdc++.h> 

using namespace std;

vector< map<int,int> > graph;

long int prim() {
    long int resp;
    resp = 0;

    set<int> visited;
    map<int,int>::iterator it;
    priority_queue< pair<int, pair<int,int> > > pilha;
    pair<int, pair<int,int> > atual;

    pilha.push( make_pair(0, make_pair(0,0) ) );

    while( !pilha.empty() ) {
        atual = pilha.top();
        pilha.pop();

        if( visited.find(atual.second.first) == visited.end() ) {
            resp += graph[atual.second.first][atual.second.second]; 
            visited.insert(atual.second.first); 

            for( it=graph[atual.second.first].begin(); it!=graph[atual.second.first].end(); ++ it ) {
                if( visited.find(it->first)==visited.end() ) {
                    pilha.push( make_pair((-it->second), make_pair(it->first, atual.second.first) ) ); 
                } 
            } 
        }
    }
    return resp; 
}


int main() {
    
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int r, c, i, v, w, p;

    cin >> r >> c;

    graph.resize(r);

    for( i=0; i<c; i++ ) {
        cin >> v >> w >> p;
        v--; w--;
        graph[v][w] = p;
        graph[w][v] = p;
    } 

    cout << prim() << endl;

    return 0;
}
