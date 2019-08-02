#include<bits/stdc++.h>
#define MOD 1000000007ll
using namespace std;

typedef long long ll; 

stack<ll> myStack;
vector<ll> cost, aux;
vector<int> visited;
vector<vector<ll>> graph;
vector<vector<ll>> trans;

void dfs(ll node) {
    visited[node] = 1;
    for(ll i=0; i<(ll)graph[node].size(); i++) {
        if(visited[graph[node][i]]==0) dfs(graph[node][i]);
    }
    myStack.push(node);
}

void dfs2(ll node) {
    visited[node] = 0;
    for(ll i=0; i<(ll)trans[node].size(); i++) {
        if(visited[trans[node][i]]==1) dfs2(trans[node][i]);
    }
    aux.push_back(node);
}

int main() {
    ll n, i, m, v1, v2, next, mini, qtd, finalCost, numbOfWays; 
    scanf("%lld",&n);
    cost.resize(n);
    graph.resize(n);
    trans.resize(n);

    for(i=0; i<n; i++) {
        scanf("%lld",&cost[i]);
    }

    scanf("%lld",&m);
    for(i=0; i<m; i++) {
        scanf("%lld%lld",&v1,&v2);
        v1--; v2--;
        graph[v1].push_back(v2);
        trans[v2].push_back(v1);
    }
    visited.resize(n,0);
    for(i=0; i<n; i++) {
        if(visited[i]==0) dfs(i);    
    }
    
    finalCost = 0; numbOfWays = 1;
    while(!myStack.empty()) {
        next = myStack.top();
        myStack.pop();
        
        if(visited[next]==1) {
            aux.clear();
            dfs2(next);
            mini = numeric_limits<ll>::max();
            for(i=0; i<(ll)aux.size(); i++) {
                mini = min(mini,cost[aux[i]]); 
            }      
            qtd = 0;      
            for(i=0; i<(ll)aux.size(); i++) {
                if(cost[aux[i]]==mini) qtd++;
            }
            finalCost += mini;
            numbOfWays = (numbOfWays * qtd)%MOD;
        }
    }
    printf("%lld %lld\n",finalCost,numbOfWays);  
    return 0;
}
