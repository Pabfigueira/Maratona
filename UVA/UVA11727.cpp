#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int t, a, num;
    vector<int> vetor;

    cin >> t;

    for( a=0; a<t; a++ ) {
        vetor.clear();
        vetor.resize(3);
    
        cin >> vetor[0] >> vetor[1] >> vetor[2];

        sort(vetor.begin(),vetor.end());

        cout << "Case " << a+1 << ": ";
        cout << vetor[1] << '\n'; 
    }    
    
    return 0;
}