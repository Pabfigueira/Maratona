#include <bits/stdc++.h> 

using namespace std;

int main() {
    
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    vector<int> vetor(10005,0);
    int a, b, c, limit, i;

    limit = 0;

    while( cin >> a >> b >> c ) {
        for( i=a; i<c; i++ ) {
            vetor[i] = max(vetor[i],b);
        }
        limit = max(limit,c);
    }

    i = 1;

    while( i < limit ) {
        if( i != 1 ) cout << " "; 
        cout << i;
        cout << " " <<  vetor[i];
        i++;
        while( i<limit  && vetor[i]==vetor[i-1] ) {
            i++;
        }
            
    }
    cout <<  " " << limit << " " << 0;
    cout << "\n";
    return 0;
}
