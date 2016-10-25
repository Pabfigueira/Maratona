#include <bits/stdc++.h> 

#define INF numeric_limits<int>::max()

using namespace std;

void dijkstra( int v, int n, vector< vector< pair<int,int> > > &graph, vector<int> &cost ) {
    set< pair<int, int> > pq;

    pq.insert( make_pair(0,v) );

    pair<int,int> atual;

    while( !pq.empty() ) {
        atual = *pq.begin();
        pq.erase(pq.begin());

        if( cost[atual.second] < atual.first ) continue;
        cost[atual.second] = atual.first;
        
        for( int i=0; i<graph[atual.second].size(); i++ ) { 
            int to, c;
            to = graph[atual.second][i].first;
            c  = graph[atual.second][i].second;

            if( cost[to] > cost[atual.second] + c ) {
                cost[to] = cost[atual.second] + c;
                pq.insert(make_pair(cost[to],to));
            }
        } 
    }
}


int main() {
    
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int q, n, m, k, s, t, i, a, b, c, res;

    vector< vector< pair<int,int> > > graphA;
    vector< vector< pair<int,int> > > graphB;

    vector<int> A;
    vector<int> B;

    cin >> q;

    while( q ) {
        cin >> n >> m >> k >> s >> t;

        s--; t--;

        graphA.clear();
        graphA.resize(n);

        graphB.clear();
        graphB.resize(n);

        for( i=0; i<m; i++ ) {
            cin >> a >> b >> c;
            a--; b--;
            graphA[a].push_back( make_pair(b,c) );
            graphB[b].push_back( make_pair(a,c) ); 
        }

        A.clear();
        A.resize(n,INF);

        B.clear();
        B.resize(n,INF);

        dijkstra(s,n,graphA, A);
        dijkstra(t,n,graphB, B);

        res = A[t];

        for( i=0; i<k; i++ ) {
            cin >> a >> b >> c;
            a--; b--;
 
            if( A[a]!=INF && B[b]!=INF ) {
                res = min(res, A[a]+B[b]+c );
            }

            if( B[a]!=INF && A[b]!=INF) {
                res = min(res, B[a]+A[b]+c );
            }       
        }

        if( res==INF ) cout << -1 << '\n';
        else cout << res << '\n';     
        q--;       
    }

    return 0;
}
