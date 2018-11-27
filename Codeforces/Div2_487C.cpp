#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main() {

    vector< pair<ll,char> > vetor(4);
    ll i, j;
    
    for( i=0; i<4; i++ ) {
        scanf("%lld",&vetor[i].first);
        vetor[i].second = (char)(i+'A');
    }

    vector< vector<char> > matrix(50,vector<char>(50,'X'));

    sort(vetor.begin(),vetor.end());

    i = 0;
    while( vetor[0].first > 1 ) {
        for( j=0; j<50; j++ ) {
            if( i%2==0 ) {
                if( j%2==0 and vetor[0].first > 1) {
                    matrix[i][j] = vetor[0].second;
                    vetor[0].first--;    
                } else {
                    matrix[i][j] = vetor[1].second;
                    if( j%2==0 and i>0 ) vetor[1].first++;
                }
            } else { 
                if( j%2==1 and vetor[0].first > 1 ) {
                    matrix[i][j] = vetor[0].second;
                    vetor[0].first--;
                } else { 
                    matrix[i][j] = vetor[1].second;
                    if( j%2==1 and i>0 ) vetor[1].first++;
                }
            }
        }
        if( vetor[0].first > 1 ) vetor[1].first -= 25;    
        i++;
    } 
    
    // Completing with second
    for( j=0; j<50; j++ ){
        matrix[i][j] = vetor[1].second;
    }
    vetor[1].first--;
    i++;

    // Completing with first
    for( j=0; j<50; j++ ){
        matrix[i][j] = vetor[0].second;
    }
    i++;
    
    // make vetor[1] empty
    while( vetor[1].first > 0 ) {
        for( j=0; j<50; j++ ){
            if( j==0 or j==49 ) matrix[i][j] = vetor[0].second;
            else {
                if( i%2==0 ) {
                    if( j%2==0 and vetor[1].first > 0 ) {
                        matrix[i][j] = vetor[1].second;
                        vetor[1].first--;
                    } else {
                        matrix[i][j] = vetor[0].second;
                    }
                } else {
                    if( j%2==1 and vetor[1].first > 0 ) {
                        matrix[i][j] = vetor[1].second;
                        vetor[1].first--;
                    } else {
                        matrix[i][j] = vetor[0].second;
                    }
                }
            }
        }
        i++;
        for( j=0; j<50; j++ ) {
            matrix[i][j] = vetor[0].second;
        }
        i++;
    } 
    
    // make vetor[2] empty
    while( vetor[2].first > 0 ) {
        for( j=0; j<50; j++ ){
            if( j==0 or j==49 ) matrix[i][j] = vetor[0].second;
            else {
                if( i%2==0 ) {
                    if( j%2==0 and vetor[2].first > 0 ) {
                        matrix[i][j] = vetor[2].second;
                        vetor[2].first--;
                    } else {
                        matrix[i][j] = vetor[0].second;
                    }
                } else {
                    if( j%2==1 and vetor[2].first > 0 ) {
                        matrix[i][j] = vetor[2].second;
                        vetor[2].first--;
                    } else {
                        matrix[i][j] = vetor[0].second;
                    }
                }
            }
        }
        i++;
        for( j=0; j<50; j++ ) {
            matrix[i][j] = vetor[0].second;
        }
        i++;
    }

    // make vetor[3] empty
    while( vetor[3].first > 0 ) {
        for( j=0; j<50; j++ ){
            if( j==0 or j==49 ) matrix[i][j] = vetor[0].second;
            else {
                if( i%2==0 ) {
                    if( j%2==0 and vetor[3].first > 0 ) {
                        matrix[i][j] = vetor[3].second;
                        vetor[3].first--;
                    } else {
                        matrix[i][j] = vetor[0].second;
                    }
                } else {
                    if( j%2==1 and vetor[3].first > 0 ) {
                        matrix[i][j] = vetor[3].second;
                        vetor[3].first--;
                    } else {
                        matrix[i][j] = vetor[0].second;
                    }
                }
            }
        }
        i++;
        for( j=0; j<50; j++ ) {
            matrix[i][j] = vetor[0].second;
        }
        i++;
    } 

    while( i<50 ) {
        for( j=0; j<50; j++ ) {
            matrix[i][j] = vetor[0].second;
        }
        i++;
    }
 
    printf("50 50\n");
    for( i=0; i<50; i++ ) {
        for( j=0; j<50; j++ ) {
            printf("%c",matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}
