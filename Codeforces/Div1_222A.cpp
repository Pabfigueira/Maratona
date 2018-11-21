#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

vector< vector<char> > matrix;
map< pair<ll,ll>, vector<pair<ll,ll> > > graph;
map< pair<ll,ll>, ll> levelMap;
map< pair<ll,ll>, ll>::iterator ita;


void dfs( pair<ll,ll> node, ll level ) {
    vector< pair<ll,ll> >::iterator it;
    levelMap[node] = level;

    for( it=graph[node].begin(); it!=graph[node].end(); ++it ) {
        if( levelMap.find(*it) == levelMap.end() ) {
            dfs(*it, level+1); 
        }
    }
}


int main() {

    ll n, m, k, i, j;
    char trash;

    scanf("%lld%lld%lld",&n,&m,&k);

    matrix.resize(n, vector<char>(m));

    for( i=0; i<n; i++ ) {
        scanf("%c",&trash);
        for( j=0; j<m; j++ ) {
            scanf("%c",&matrix[i][j]);
        }
    }

    for( i=0; i<n; i++ ) {
        for( j=0; j<m; j++ ) {
            if( matrix[i][j]=='.' ) {
                if( i>0 and matrix[i-1][j] == '.' ) {
                    graph[make_pair(i,j)].push_back(make_pair(i-1,j)); 
                    graph[make_pair(i-1,j)].push_back(make_pair(i,j)); 
                }
                if( i<n-1 and matrix[i+1][j] == '.') {
                    graph[make_pair(i,j)].push_back(make_pair(i+1,j)); 
                    graph[make_pair(i+1,j)].push_back(make_pair(i,j)); 
                }
                if( j>0 and matrix[i][j-1] == '.' ) {
                    graph[make_pair(i,j)].push_back(make_pair(i,j-1)); 
                    graph[make_pair(i,j-1)].push_back(make_pair(i,j)); 
                }
                if( j<m-1 and matrix[i][j+1] == '.' ) {
                    graph[make_pair(i,j)].push_back(make_pair(i,j+1)); 
                    graph[make_pair(i,j+1)].push_back(make_pair(i,j)); 
                }
            }     
        }
    } 

    dfs( graph.begin()->first, 0 );
    
    vector< pair<ll, pair<ll,ll> > > vetor;
    
    for( ita=levelMap.begin(); ita!=levelMap.end(); ++ita ) {
        vetor.push_back( make_pair(-ita->second, ita->first) ); 
    }

    sort(vetor.begin(),vetor.end());

    for( i=0; i<k; i++ ) {
        matrix[vetor[i].second.first][vetor[i].second.second] = 'X';
    }        


    for( i=0; i<n; i++ ) {
        for( j=0; j<m; j++ ) {
            printf("%c",matrix[i][j]);             
        }
        printf("\n");
    }

    return 0;
}
