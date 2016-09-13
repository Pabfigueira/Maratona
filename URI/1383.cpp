#include <bits/stdc++.h>

using namespace std; 

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    int n, a, i, j;

    vector< vector<int> > matriz;
    set<int> group;
    bool error;
    
    cin >> n;
     

    for( a=0; a<n; a++ ) {
        matriz.clear();
        matriz.resize( 9, vector<int>(9) );
    
        error = false;

        for( i=0; i<9; i++ ) {
            group.clear();
            for( j=0; j<9; j++ ) { 
                cin >> matriz[i][j];

                if( matriz[i][j]>=1 && matriz[i][j]<=9 ) {
                    group.insert( matriz[i][j] );
                }
            }
            if( group.size()!=9 ) {
                error = true;
            }
        }

        if( !error ) {
            
            for( j=0; j<9; j++ ) {
                group.clear();
                for( i=0; i<9; i++ ) {
                    if( matriz[i][j]>=1 && matriz[i][j]<=9 ) {
                        group.insert( matriz[i][j] );
                    }
                }
                if( group.size()!=9 ) {
                    error = true;
                }
            }
        }


        if( !error ) {

            for( i=0; i<9; i+=3 ) {
                for( j=0; j<9; j+=3 ) {
                    group.clear();
                    
                    if( (matriz[i][j]>=1 && matriz[i][j]<=9) && (matriz[i][j+1]>=1 && matriz[i][j+1]<=9) && (matriz[i][j+2]>=1 && matriz[i][j+2]<=9) &&
                        (matriz[i+1][j]>=1 && matriz[i+1][j]<=9) && (matriz[i+1][j+1]>=1 && matriz[i+1][j+1]<=9) && (matriz[i+1][j+2]>=1 && matriz[i+1][j+2]<=9) &&
                        (matriz[i+2][j]>=1 && matriz[i+2][j]<=9) && (matriz[i+2][j+1]>=1 && matriz[i+2][j+1]<=9) && (matriz[i+2][j+2]>=1 && matriz[i+2][j+2]<=9) ) { 

                        group.insert( matriz[i][j] );    group.insert( matriz[i][j+1] );    group.insert( matriz[i][j+2] );
                        group.insert( matriz[i+1][j] );  group.insert( matriz[i+1][j+1] );  group.insert( matriz[i+1][j+2] );
                        group.insert( matriz[i+2][j] );  group.insert( matriz[i+2][j+1] );  group.insert( matriz[i+2][j+2] );
                    }
                    
                    if( group.size()!=9 ) {
                        error = true;
                    }
                }
            }

        }
        
        cout << "Instancia " << a+1 << '\n';        

        if( !error ) {
            cout << "SIM\n\n";
        } else {
            cout << "NAO\n\n";
        }
    }
    return 0;
}
