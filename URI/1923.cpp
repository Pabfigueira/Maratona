#include<bits/stdc++.h>

using namespace std;

map<string,set<string>> graph;
set<string> ans;
set<string>::iterator it;

void bfs(int g) {
    pair<string,int> next;
    queue<pair<string,int>> myQueue;
    myQueue.push(make_pair("Rerisson",0));
    ans.insert("Rerisson");
    
    while(!myQueue.empty()) {
        next = myQueue.front();
        myQueue.pop();
        if(next.second==g) continue;
    
        for(it=graph[next.first].begin(); it!=graph[next.first].end(); ++it) {
            if(ans.find(*it)==ans.end()) {
                ans.insert(*it);
                myQueue.push(make_pair(*it,next.second+1));
            }
        }
    } 
}

int main() {
    ios_base::sync_with_stdio(false);
    int n, g, i;
    string nodeA, nodeB;
    cin >> n >> g;
    for(i=0; i<n; i++) {
        cin >> nodeA >> nodeB;
        graph[nodeA].insert(nodeB);
        graph[nodeB].insert(nodeA);
    }
    
    bfs(g); 
    
    cout << ans.size()-1 << endl;
    for(it=ans.begin(); it!=ans.end(); ++it) {
        if(*it != "Rerisson") cout << *it << endl;
    } 
    return 0;
}
