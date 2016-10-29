#include <bits/stdc++.h> 

using namespace std;

int main() {
    
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int k, n, i, ant, sum, maxi, indice;

    cin >> n >> k;

    vector<int> vetor(n);

    indice = 0;
    maxi = numeric_limits<int>::max();
    sum = 0;
    ant = 0;
    
    for( i=0; i<n; i++ ) {
        cin >> vetor[i];
        sum += vetor[i];

        if( ((i-ant)+1) == k ) {
            if( sum <= maxi ) {  
                maxi = sum;
                indice = ant+1;
            }  
            sum -= vetor[ant];
            ant++;                     
        }
    }
    cout << indice << '\n';
    return 0;
}
