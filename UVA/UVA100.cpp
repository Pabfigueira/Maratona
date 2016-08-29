#include <bits/stdc++.h>
#define MAX 1000000

using namespace std; 

vector< long int > vetor(MAX+1, 0); 

long int calc( long int value ) {
    if( value > MAX ) {
        if( value%2==0 ) {
            return 1 + calc ( value/2 );
        } else {
            return 1 + calc ( (value*3)+1 );
        }
    } else {
        if( vetor[value] ) {
            return vetor[value];
        } else {
            if( value%2==0 ) {
                return vetor[value] = 1 + calc( value/2 );
            } else {
                return vetor[value] = 1 + calc( (value*3)+1 );
            }
        } 
    }
}



int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    long int i, n, a, b, max;

    vetor[1] = 1;
    //calc( MAX );

    while( cin >> a >> b ) {
        cout << a << " " << b << " ";
        if( a > b ) {
            swap(a,b);
        }
        max = 0; 
        for( i=a; i<=b; i++ ) {
            if( max < calc(i) ) {
                max = vetor[i];
            }
        }
        cout << max << '\n';
    }
    return 0;
}
