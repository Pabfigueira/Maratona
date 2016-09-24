#include <bits/stdc++.h> 

using namespace std;

int main() {
    
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    long long int n, k, i, cost;

    cin >> n >> k;

    vector< pair< long long int ,pair< long long int ,pair< long long int, long long int > > > > vetor(n);

    for( i=0; i<n; i++ ) {
        cin >> vetor[i].second.first;
    }

    for( i=0; i<n; i++ ) {
        cin >> vetor[i].second.second.second;
        vetor[i].first = vetor[i].second.second.second / vetor[i].second.first;
        vetor[i].second.second.first = vetor[i].second.second.second % vetor[i].second.first;
    } 

    sort( vetor.begin(), vetor.end() );

    /*/ *************Debug*****************
    for( i=0; i<n; i++ ) {
        cout << vetor[i].first << " " << vetor[i].second.first << " " << vetor[i].second.second.first << " " << vetor[i].second.second.second << endl;
    }
    // ***********************************/

    i = 0;
    while( i<n && k ) {
        if( i == n-1 ) {
            k += vetor[i].second.second.first;

            vetor[i].first += k/vetor[i].second.first;
            
            break;
        } else {

            if( vetor[i+1] == vetor[i] ) {
                vetor[i+1].second.first         += vetor[i].second.first;
                vetor[i+1].second.second.first  += vetor[i].second.second.first;
                i++; 
            } else {
                cost = ((vetor[i+1].first - vetor[i].first) * vetor[i].second.first) - vetor[i].second.second.first;

                if( k >= cost ) {
                    k -= cost;
                    vetor[i+1].second.first += vetor[i].second.first;
                    i++; 
                } else {
                    k += vetor[i].second.second.first;
                    vetor[i].first += k/vetor[i].second.first;
                    break;
                }
            } 
        }
    }
    cout << vetor[i].first << '\n'; 
    return 0;
}
