#include <bits/stdc++.h> 

using namespace std;

int main() {
    
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n, m, i, qt, pos;
    vector<int> vetor;
    vector<int> aux;

    while( cin >> n >> m && (n||m) ) { 
        vetor.clear();
        vetor.resize(n+1,0);
        aux.clear();
        aux.resize(n);

        for( i=1; i<=n; i++ ) {
            aux[i-1] = i;    
        }

        for( i=1; i<=m; i++ ) {
            cin >> qt;
            vetor[ aux[qt] ] = i;
            aux.erase(aux.begin()+qt);
        }

        for( i=m+1; i<=n; i++ ) {
            vetor[ aux[0] ] = i;
            aux.erase(aux.begin());
        }

        cout << vetor[1];
        for( i=2; i<=n; i++ ) {
            cout << " " << vetor[i];
        } 
        cout << '\n';    
    }
    return 0;
}
