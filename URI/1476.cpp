#include <bits/stdc++.h>

using namespace std;

vector< vector< pair<int, int> > > graph;
vector< vector< pair<int, int> > > agm;

vector< int > dad;
vector< int > level;
vector< int > p;  
vector< int > auxVisited;
vector< int > dist;

int n, m, s, i, a, b, c, j, one, two, cost, maxLevel;


void build() {
    vector<int> visited(n,0);

    visited[0] = 1;

    priority_queue< pair<int, pair<int,int> > > queue;

    for( j=0; j<graph[0].size(); j++ ) {
        queue.push( make_pair( graph[0][j].second, make_pair(0, graph[0][j].first) ) ); 
    }

    while( !queue.empty() ) {
        cost = queue.top().first;
        one  = queue.top().second.first;
        two  = queue.top().second.second;
        
        queue.pop();
        
        if( visited[two]==0 ) {

            //cout << one << " " << two << " " << cost << "\n";
            visited[two] = 1;
            agm[one].push_back( make_pair(two, cost) );
            agm[two].push_back( make_pair(one, cost) );

            for( j=0; j<graph[two].size(); j++ ) {
                if( visited[ graph[two][j].first ] == 0 ) {
                    queue.push( make_pair( graph[two][j].second, make_pair(two, graph[two][j].first) ) );
                }
            }
        }
    }
}

void findDad( int atual, int father, int nivel) {
    dad[atual] = father;    
    level[atual] = nivel;

    maxLevel = max(maxLevel,nivel);

    for( int z=0; z<agm[atual].size(); z++ ) {
        if( auxVisited[agm[atual][z].first] == 0 ) {
            auxVisited[agm[atual][z].first] = 1;
            dist[agm[atual][z].first] = agm[atual][z].second;
            findDad(agm[atual][z].first,atual,nivel+1);
        }
    }
    return;
}

void dfs( int atual, int nr ) {
    if( level[atual] < nr ) {
        p[atual] = 0;
    } else {
        if( !(level[atual]%nr) ) {
            p[atual] = dad[atual];
        } else {
            p[atual] = p[dad[atual]];
        }
    }

    for( int z=0; z<agm[atual].size(); z++ ) {
        if( auxVisited[agm[atual][z].first] == 0 ) {
            auxVisited[agm[atual][z].first] = 1;
            dfs(agm[atual][z].first,nr); 
        }
    }
    return;
}

int LCA( int x, int y ) {
    
    int minimo = numeric_limits<int>::max();

    while( p[x] != p[y] ) {
        if( level[x] > level[y] ) {

        	int option = x;

        	while( option!=p[x] ) {
        		minimo = min(minimo,dist[option]);
        		option = dad[option];
        	}
            x = p[x];
        } else {
        	int option = y;
        	while( option!=p[y] ) {
        		minimo = min(minimo,dist[option]);
        		option = dad[option];
        	}
            y = p[y];
        }
    }

    while( x != y ) {
        if( level[x] > level[y] ) {
            minimo = min( minimo,dist[x] );
            x = dad[x];
        } else {
            minimo = min( minimo,dist[y]);
            y = dad[y];
        }
    } 

    return minimo;
    //return x;
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    while( cin >> n >> m >> s ) {
        graph.clear();
        graph.resize(n, vector< pair<int,int> > ());

        agm.clear();
        agm.resize(n, vector< pair<int,int> > ());

        p.clear();
        p.resize(n);
        dad.clear();
        dad.resize(n);
        level.clear();
        level.resize(n,0); 
        auxVisited.clear();
        auxVisited.resize(n,0);   
        maxLevel = 0;

        dist.clear();
        dist.resize(n,0);

        for( i=0; i<m; i++ ) {
            cin >> a >> b >> c;
            a--; b--;

            graph[a].push_back( make_pair(b,c) );
            graph[b].push_back( make_pair(a,c) );    
        }
        
        build();

        auxVisited[0] = 1;
        findDad(0,0,0);
        auxVisited.clear();
        auxVisited.resize(n,0);
        auxVisited[0] = 1;
        dfs(0,sqrt(maxLevel));
        

        for( i=0; i<s; i++ ) {
            cin >> a >> b;
            a--; b--;
            cout << LCA(a,b) << endl;
        }       
    }

    return 0;
}
