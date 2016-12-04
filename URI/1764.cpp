#include <bits/stdc++.h> 

using namespace std;

vector< map<int,int> > graph;
map<int,int>::iterator it;

long int prim() {
    long int resp = 0;
    set<int> visited;
    priority_queue< pair<int, pair<int,int> > >pilha;
    pair<int, pair<int,int> > atual;

    pilha.push( make_pair(0, make_pair(0,0)) ); 

    while( !pilha.empty() ) {
        atual = pilha.top();
        pilha.pop();
        
        if( visited.find(atual.second.first) == visited.end() ) {
            visited.insert( atual.second.first );

            resp += graph[atual.second.first][atual.second.second];

            for(it=graph[atual.second.first].begin(); it!=graph[atual.second.first].end(); ++it ) {
                if( visited.find( it->first ) == visited.end() ) {
                    pilha.push( make_pair( (-it->second) , make_pair(it->first ,atual.second.first) ) ); 
                }     
            }
        }
    }
    return resp;
}


int main() {
    
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int m, n, a, b, c, i;
    
    while( cin >> m >> n && (m||n) ) {
        graph.clear();
    
        graph.resize(m);

        for( i=0; i<n; i++ ) {
            cin >> a >> b >> c;
            graph[a][b] = c;
            graph[b][a] = c;
        }
        cout << prim() << endl;   
    }
    return 0;
}
