#include <bits/stdc++.h>

using namespace std;

int main() {
  
  ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

  int n, p, i, qt, j, period;
  string word, name;
  double price;

  vector< pair<double, pair<double, pair< int, string> > > > vetor;

  period = 1;

  while( cin >> n >> p && (n||p) ) {
    if( period!=1 ) cout << '\n'; 
    vetor.clear();

    getline(cin,word);

    for( i=0; i<n; i++ ) {
      getline(cin,word);
    }

    for( i=0; i<p; i++ ) {
      getline(cin,name);
      cin >> price >> qt;
        
      getline(cin,word);


      for( j=0; j<qt; j++ ) {
        getline(cin,word);
      }

      vetor.push_back( make_pair( qt/(double)n, make_pair( price*(-1), make_pair(i*(-1), name) ) ) );
      
    }

    sort(vetor.begin(),vetor.end());

    cout << "RFP #" << period++ << '\n';
    cout << vetor[vetor.size()-1].second.second.second << '\n';
  } 
  return 0;
}