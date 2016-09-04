#include <bits/stdc++.h>

using namespace std;

class ShorterSuperSum {

    public:
        int calculate( int k, int n );

};


int ShorterSuperSum::calculate( int k, int n ) {
    
    int i, j;

    vector< vector<unsigned long long int > > sum(15,vector<unsigned long long int>(15));
    //vector< vector<int > > sum(15,vector<int>(15));


    for( i=0; i<=14; i++ ) {
        for( j=0; j<=14; j++ ) {
            if( i == 0 ) {
                sum[i][j] = j;
            } else if ( j==0 ) {
                sum[i][j] = 0;
            } else {
                sum[i][j] = sum[i][j-1] + sum[i-1][j];
            }
        }
    }

    return sum[k][n];
}

/*int main(){
    int k, n;
    while( cin >> k >> n ) {
        cout << calculate(k,n) << endl;
    } 
    return 0;
}*/
