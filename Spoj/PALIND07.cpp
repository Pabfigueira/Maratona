#include <bits/stdc++.h> 

using namespace std;

unsigned long long int eleva( unsigned long long int a, unsigned long long int b, unsigned long long int e ) {
    unsigned long long int d, c = 1;
    for( d=0; d<b; d++ ) {
        if( c > e ) return c;
        c *= a;
    }  
    return c; 
} 


int main() {
    
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    unsigned long long int n, tam, pos, cada, man, i, j;

    cin >> n;
    
    vector<char> vetor(n);

    for( tam=0; tam<n; tam++ ) {
        cin >> vetor[tam];
    }
    
    cin >> tam >> pos;
    vector<char> result(tam);
    
    i = 0;
    j = tam-1;

    while( tam > 0 ) {
        
        cada = eleva( n, ((tam-1) / 2), pos );
        man = (pos-1) / cada;
       
        result[i] = vetor[man];
        i++;
        if( tam > 1 ) {
            result[j] = vetor[man];
            j--;
            tam -= 2;
        } else {
            tam -= 1;
        }
        pos -= (man*cada);
    } 
    for( i=0; i<result.size(); i++ ) {
        cout << result[i];
    }
    cout << "\n";
    return 0;
}
