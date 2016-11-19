#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n, i, a, b;

    cin >> n;
    
    vector< pair<int,int> > vetor(n);
   
    for( i=0; i<n; i++ ) {
        cin >> a >> b;
        vetor[i] = make_pair(a,b);
    }

    sort(vetor.begin(),vetor.end());

    bool achou = false;

    for( i=1; i<n; i++ ) { 
        if( vetor[i].second < vetor[i-1].second ) 
            achou = true;
    }

    if( achou ) {
        cout << "Happy Alex\n";
    } else {
        cout << "Poor Alex\n";
    }
    return 0;
}
