#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector< set<ll> > graph;
set<ll>::iterator it;
vector<ll> inDegree;


void topSort() {
    ll i, front;

    for( i=0; i<30; i++ ) {
        for( it=graph[i].begin(); it!=graph[i].end(); ++it ) {
            inDegree[*it]++;
        }
    }
    
    queue<ll> order;

    for( i=0; i<=25; i++ ) {
        if( inDegree[i]==0 ) {
            order.push(i);     
        } 
    }

    while( !order.empty() ) {
        front = order.front();
        order.pop();
        cout << (char)(front + 'a');
        for( it=graph[front].begin(); it!=graph[front].end(); ++it ) {
            inDegree[*it]--;
            if( inDegree[*it] == 0 ) order.push(*it);         
        }         
    }
}

bool dfs( ll node, vector<ll>& color ) {
    set<ll>::iterator ita;
    color[node] = 1;
    for( ita=graph[node].begin(); ita!=graph[node].end(); ++ita ) {
        if( color[*ita] == 1 ) return false;
        if( color[*ita]==0 ) {
            if( !dfs(*ita, color) ) return false;
        }         
    } 
    color[node] = 2;
    return true;
}

bool isCyclic() {
    vector<ll> color(30,0);
    ll i;

    for( i=0; i<=25; i++ ) {
        if( color[i]==0 ) {
            if( !dfs(i,color) ) return true;
        }
    } 
    return false;
}


int main() {
    
    ios_base::sync_with_stdio(false);

    ll n, i, j, a, b;

    graph.resize(30);
    inDegree.resize(30);

    cin >> n;  
    vector<string> words(n);

    for( i=0; i<n; i++ ) {
        cin >> words[i];
    }

    for( i=0; i<n; i++ ) {
        for( j=i+1; j<n; j++ ) {
            a = b = 0;
            while( a<words[i].size() and words[i][a]==words[j][b] ) {
                a++; b++;
                if( a!=words[i].size() and b==words[j].size() ) {
                    cout << "Impossible\n";
                    return 0;
                }
            }
            if( a!=words[i].size() ) {
                graph[words[i][a] - 'a'].insert(words[j][b]-'a');
            }
        }
    }    

    if( isCyclic() ) {
        cout << "Impossible\n";
        return 0;
    }

    topSort();
    cout << endl;

    return 0;
}
