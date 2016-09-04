#include <bits/stdc++.h>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    long long int n, i, j;
    cin >> n;

    vector< vector<long long int> > matriz(n+1, vector<long long int>(n+1,0));
    
    for(i=0;i<=n;i++) {
        matriz[0][i] = 1;
        matriz[i][0] = 1;
    }

    for( i=1; i<=n; i++ ) {
        for( j=1; j<=n; j++ ) {
            matriz[i][j] = matriz[i-1][j] + matriz[i][j-1];   
        }
    }

    cout << matriz[n][n] << '\n';
    return 0;  
}
