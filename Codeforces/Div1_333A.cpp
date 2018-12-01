#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

ll n;

vector< vector<ll> > graphA;
vector< vector<ll> > graphB;
vector<ll>::iterator it;

ll bfs( vector< vector<ll> >& graph ) {
    vector<ll> visited(n,0);
    
    queue< pair<ll,ll> > fila;
    pair<ll,ll> top;

    fila.push( make_pair(0,0) );
    visited[0] = 1;

    while( !fila.empty() ) {
        top = fila.front();
        fila.pop();

        if( top.first == n-1 ) return top.second; 
        
        for( it=graph[top.first].begin(); it!=graph[top.first].end(); ++it ) {
            if( visited[*it]==0 ) {
                visited[*it] = 1;
                fila.push( make_pair(*it,top.second+1) );
            } 
        }      
    }
    return -1;    
}

int main() {

    ll m, i, j, a, b;

    set< pair<ll,ll> > edges;
    set< pair<ll,ll> >::iterator setIt;

    scanf("%lld%lld",&n,&m);

    graphA.resize(n);
    graphB.resize(n);
    
    vector<ll> visited(n,0);


    for( i=0; i<n; i++ ) {
        for( j=i+1; j<n; j++ ) {
            edges.insert( make_pair(i,j) );
        }
    }

    for( i=0; i<m; i++ ) {
        scanf("%lld%lld",&a,&b);     
        a--; b--;
        if( a>b ) swap(a,b);
        edges.erase( make_pair(a,b) );
        graphA[a].push_back(b);
        graphA[b].push_back(a); 
    }
    for( setIt=edges.begin(); setIt!=edges.end(); ++setIt ) {
        graphB[setIt->first].push_back(setIt->second);
        graphB[setIt->second].push_back(setIt->first); 
    }

    ll resA, resB;
    
    resA = bfs(graphA);
    resB = bfs(graphB);

    if( resA==-1 or resB==-1 ) printf("-1\n");
    else printf("%lld\n",max(bfs(graphA),bfs(graphB)));

    return 0;
}
