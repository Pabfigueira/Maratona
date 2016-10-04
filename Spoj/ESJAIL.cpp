#include <bits/stdc++.h>

using namespace std;

vector< vector<int> > graph;

map<int, int> key;
set<int> blockDoor;

int n, k, m, i, a, b;
bool end;

bool busca(){
    vector<int> visited(n,0);
    stack<int> pilha;

    end = false;    

    visited[0] = 1;
    pilha.push(0);

    
    while( !pilha.empty() ) {
        a = pilha.top();
        pilha.pop();
        
        //cout << "-> " << a << endl;

        if( a==n-1 ) {
            end = true;
            break;
        }

        for( b=0; b<graph[a].size(); b++ ){
            if( visited[graph[a][b]]==0 ) {
                visited[graph[a][b]] = 1;

                if( key.find(graph[a][b]) != key.end() ) {
                    if( visited[ key[ graph[a][b] ] ] == 1 ){
                        pilha.push( key[ graph[a][b] ] );
                    }
                    blockDoor.erase( key[ graph[a][b] ] );
                }

                if( blockDoor.find(graph[a][b]) == blockDoor.end() ) {
                    pilha.push( graph[a][b] );    
                }
            }
        }        
    }  
     
    return end;
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    while( cin >> n >> k >> m && (n+k+m != -3) ) {
        graph.clear();
        graph.resize(n, vector<int>());
        key.clear();
        blockDoor.clear();

        for( i=0; i<k; i++ ) {
            cin >> a >> b;
            a--; b--;
            
            key[a] = b;
            blockDoor.insert(b); 
        }


        for( i=0; i<m; i++ ) {
            cin >> a >> b;
            a--; b--;

            graph[a].push_back(b);
            graph[b].push_back(a);
        } 

        if( blockDoor.find(0)==blockDoor.end() && busca() ) {
            cout << "Y\n";
        } else {
            cout << "N\n";
        }
    }
    
    return 0;
}
