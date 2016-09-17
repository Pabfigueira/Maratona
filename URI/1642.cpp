#include <bits/stdc++.h>

using namespace std;

string line;
int n;

int doisPonteiros() {
  int l, r, maximo, cont;

  l = 0; 
  r = 0;
  maximo = 0;
  cont = 0;

  map<char,int> vetor;
  map<char,int>::iterator it;

  while( l<line.size() ) {
    while( r<line.size() ) {
      if(vetor[line[r]] == 0 ) {
        cont++;
      }
      vetor[line[r]]++;
      if( cont > n ) {
        break;
      }
      r++;
    }
    maximo = max(maximo,r-l);
    vetor[line[l]]--;
    if( vetor[line[l]] == 0 ) {
    	cont--;
        vetor.erase(line[l]);
    }
    l++;
    r++;
  }
  return maximo;
}



int main() {
  ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

  while( cin >> n && n ) {
    getline(cin,line);
    getline(cin,line);

    cout << doisPonteiros() << endl;
  }
  return 0;
}
