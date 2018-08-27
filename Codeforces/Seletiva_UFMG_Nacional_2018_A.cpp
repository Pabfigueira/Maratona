#include<bits/stdc++.h>

#define ll long long int

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    
    ll n, i, m, j;
    string word;
    
    cin >> n;
    
    vector<string> indice(n);
    map<string,ll> pontos;


    for( i=0; i<n; i++ ) {
        cin >> word;
        indice[i] = word;
        pontos[word] = 0;
    }
    
    cin >> m; 
    for( i=0; i<m; i++ ) {
        for( j=0; j<n; j++ ) {
            cin >> word;
            pontos[word] += (n-j);
        }
    }
    
    vector< pair<ll, pair<ll,string> > > vetor(n);
    
    for( i=0; i<n; i++ ) {
        vetor[i].first = -pontos[indice[i]];
        vetor[i].second.first = i;
        vetor[i].second.second = indice[i];
    }
    sort(vetor.begin(),vetor.end());

    cout << vetor[0].second.second << endl;

    return 0;
}
