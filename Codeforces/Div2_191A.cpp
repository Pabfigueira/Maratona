#include <bits/stdc++.h> 

using namespace std;

int main() {
    
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n, i, j, maxi, atual;

    cin >> n;

    vector<int> ant(n,0);
    vector<int> pos(n,0);
    vector<int> vetor(n,0);

    for( i=0; i<n; i++ ) {
        cin >> vetor[i];
        ant[i] += vetor[i];

        if( i>0 ) ant[i] += ant[i-1];
    }


    for( i=n-1; i>=0; i-- ) {
        pos[i] += vetor[i];

        if( i<n-1 ) {
            pos[i] += pos[i+1];
        }   
    }

    //maxi = pos[0];
    //maxi = max( maxi, n-maxi );
    maxi = n-pos[0];

    for( i=0; i<n; i++ ) {
        atual = 0;
        for( j=i; j<n; j++ ) {
            atual += vetor[j];
            maxi = max( maxi, (ant[i]-vetor[i]) + (pos[j]-vetor[j]) + ((j-i+1) - atual));    
        }
    }
    cout << maxi << '\n';
    return 0;
}
