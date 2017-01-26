#include <bits/stdc++.h> 

using namespace std;

int main() {
    
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n, i, j;
    
    double novo;

    cin >> n;

    vector<int> vetor(n);    

    for( i=0; i<n; i++ ) {
        cin >> vetor[i];
    }

    bool achou = false;    

    j = 1;    

    while( !achou ) {
        achou = true;
        for( i=0; i<n && achou == true; i++ ) {
                
            novo = round( (vetor[i]/100.0) * j );
            
            if( round((novo*100)/(double)j) != vetor[i] ) {
                //cout << round((novo*100)/(double)j) << " " << vetor[i] << endl;
                achou = false;
            }
        }
        j++;
    }
    cout << j-1 << endl;
    return 0;
}
