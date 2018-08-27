#include <bits/stdc++.h>
#define mp make_pair

using namespace std;

typedef long long int ll;

vector< vector<ll> > graph(505,vector<ll>(505,0));
vector< vector<ll> > dist(505,vector<ll>(505,-1));
ll n, m;


ll bfs( ll node ) {
    vector<ll> visited(n,0);
    set<ll> faltosos;
    set<ll>::iterator it;
    for( ll i=0; i<n; i++ ) {
        faltosos.insert(i);
    }

    ll maximo = 0;


    queue< pair<ll,ll> > pilha;
    pair<ll,ll> next;

    pilha.push( mp(node,0) );
    visited[node] = 1;
    
    while( !pilha.empty() ) {
        next = pilha.front();
        pilha.pop();
        
        if( visited[next.first]==2 ) continue;

        visited[next.first] = 2;
        dist[node][next.first] = next.second;
        dist[next.first][node] = next.second;
        faltosos.erase(next.first);    
        maximo = max(maximo,next.second);

        for( it=faltosos.begin(); it!=faltosos.end(); ++it ) {
            if( graph[next.first][*it]==1 and visited[*it]==0 ) {
                visited[*it] = 1;
                pilha.push( mp(*it,next.second+1) );    
            } 
        }
    }
    return 2*maximo + 1;
}



int main() {

    ll i, a, b, resposta, j, h, maximo;

    scanf("%lld%lld",&n,&m);
    
    for( i=0; i<m; i++ ) {
        scanf("%lld%lld",&a,&b); 
        a--; b--;
        graph[a][b] = 1;
        graph[b][a] = 1;
    }

    resposta = numeric_limits<ll>::max();

    for( i=0; i<n; i++ ) {
        resposta = min(resposta,bfs(i));
    }

    
    for( i=0; i<n; i++ ) {
        for( j=i+1; j<n; j++ ) {
            if( graph[i][j]==1 ) {
                maximo = 0;
                for( h=0; h<n; h++ ) {
                    maximo = max(maximo, min(dist[i][h],dist[j][h]) );    
                }
                resposta = min(resposta, 2*maximo+2);     
            } 
        }
    }
    

    printf("%lld\n",resposta); 

    return 0;
}
