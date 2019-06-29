#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

ll n, m;
vector<vector<char>> matrix;    
vector<ll> visited;

ll transform(ll line, ll column) {
    return (line*m)+column;
}

bool dfs(ll line, ll column, ll father) {
    if(visited[transform(line,column)]==1) return true;    
    visited[transform(line,column)]=1;
        
    if(line>0 and matrix[line][column]==matrix[line-1][column] and transform(line-1,column)!=father) {
        if(dfs(line-1,column,transform(line,column))) return true;    
    }
    
    if(column>0 and matrix[line][column]==matrix[line][column-1] and transform(line,column-1)!=father) {
        if(dfs(line,column-1,transform(line,column))) return true;
    }

    if(line<n-1 and matrix[line][column]==matrix[line+1][column] and transform(line+1,column)!=father) {
        if(dfs(line+1,column,transform(line,column))) return true;
    }
    
    if(column<m-1 and matrix[line][column]==matrix[line][column+1] and transform(line,column+1)!=father) {
        if(dfs(line,column+1,transform(line,column))) return true;
    }
    return false;
}

int main() {
    ll i, j;
    char trash;
    scanf("%lld%lld",&n,&m);
    matrix.resize(n,vector<char>(m));
    visited.resize(n*m+5,0);

    for(i=0; i<n; i++) {
        scanf("%c",&trash);
        for(j=0; j<m; j++) {
            scanf("%c",&matrix[i][j]);
        }
    }
    
    for(i=0; i<n; i++) {
        for(j=0; j<m; j++) {
            if(visited[transform(i,j)]==0) {
                if(dfs(i,j,transform(i,j))) {
                    printf("Yes\n");
                    return 0;
                }
            }
        }
    }
    printf("No\n");
    return 0;
}
