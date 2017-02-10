#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int i, j;

    vector<string> vetor(10);

    vetor[0] = "0";    

    for( i=1; i<10; i++ ) {

        for( j=0; j<(vetor[i-1].size()-1)/2; j+=2 ) {
            vetor[i] += vetor[i-1][j];
            vetor[i] += ' ';
        }
        vetor[i] += vetor[i-1][j];
        vetor[i] += ' ';
        vetor[i] += ('0' + i);
        
        while( j<vetor[i-1].size() ) {
            vetor[i] += ' ';
            vetor[i] += vetor[i-1][j];
            j+=2;
        }

        //cout << vetor[i] << endl;
    }


    int n, white;
    
    cin >> n;

    white = vetor[n].size();


    for( i=0; i<=n; i++ ) {
        for( j=0; j<n-i; j++ ) cout << "  ";
        cout << vetor[i] << '\n';
    }

    for( i=n-1; i>=0; i-- ) {
        for( j=0; j<n-i; j++ ) cout << "  ";
        cout << vetor[i] << '\n';
    }
    return 0;
}
