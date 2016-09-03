#include <bits/stdc++.h> 

using namespace std;

int main() {
    
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int w, n, a, t, i, j, b;
    stringstream S;    
    string word;

    vector< vector<unsigned long long int > > dp; 

    cin >> t; 

    for( a=0; a<t; a++ ) {
        cin >> w >> n;
    


        dp.clear();
        dp.resize(w,vector<unsigned long long int>(n,1));

        getline(cin,word);

        for( b=0; b<w; b++ ) {
        
            S.str("");
            S.clear();

            cin >> i;

            getline(cin, word);

            if( word.size() > 0 ) {

                S << word;

                //S >> i;

                while(!S.eof()){
                    S >> j;
                    if( !S.fail() ) {
                        dp[i-1][j-1] = 0;
                    }
                }
            }
        }

        /*for( i=0; i<w; i++ ) {
            for(j=0; j<n; j++ ) {
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }*/


        
        for( i=0; i<w; i++ ) {
            for( j=0; j<n; j++ ) {


                if( dp[i][j] != 0 ) {
                    
                    if( i==0 && j==0 ) {
                        dp[i][j] = 1;
                    } else {
                        if( i==0 ) {
                            dp[i][j] = min(dp[i][j],dp[i][j-1]);
                        } else if( j==0 ) {
                            dp[i][j] = min(dp[i][j],dp[i-1][j]);
                        } else {
                            dp[i][j] = ( dp[i-1][j] + dp[i][j-1] );
                        }
                    } 
                } else {
                  //  cout << "erro";
                }

                //cout << "-> " << i << " " << j << " " << dp[i][j] << endl;
            }
        }


        /*for( i=0; i<w; i++ ) {
            for(j=0; j<n; j++ ) {
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }*/

        if( a!=0 ) cout << '\n';
        cout << dp[w-1][n-1] << '\n';
//        cout << '\n';
    }
    return 0;
}
