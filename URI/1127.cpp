#include <bits/stdc++.h> 

using namespace std;

int main() {
    
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    int m, t, i, j;

    string w1, w2, first;

    map< string, int > mapa;
    mapa["A"]  =  0;
    mapa["A#"] =  1; mapa["Bb"] =  1;
    mapa["B"]  =  2; mapa["Cb"] =  2;
    mapa["C"]  =  3; mapa["B#"] =  3;
    mapa["C#"] =  4; mapa["Db"] =  4;
    mapa["D"]  =  5; 
    mapa["D#"] =  6; mapa["Eb"] =  6;
    mapa["E"]  =  7; mapa["Fb"] =  7;
    mapa["F"]  =  8; mapa["E#"] =  8;
    mapa["F#"] =  9; mapa["Gb"] =  9;
    mapa["G"]  = 10;
    mapa["G#"] = 11; mapa["Ab"] = 11;
 

    while( cin >> m >> t && (m||t) ) {
        
        if( m==1 && t==1 ) {
            
            cin >> w1 >> w2;

            if( mapa[w1]==mapa[w2] ) {
                cout << "S\n";
            } else {
                cout << "N\n";
            }

        } else if( t==1 ) {
        
            set<int> group;

            for(i=0;i<m;i++) {
                cin >> w1;
                group.insert(mapa[w1]);        
            }

            cin >> w2;

            if( group.find(mapa[w2])!=group.end() ) {
                cout << "S\n";
            } else {
                cout << "N\n";
            }
            
        } else {
        	string music, trecho;

            cin >> w1;
            first = w1;

            for( i=1; i<m; i++ ) {
                cin >> w2;
                music += ( (((mapa[w2]+12) - mapa[w1]) % 12) + 48 );
                w1 = w2;
            }

            music += ( (((mapa[first]+12) - mapa[w1]) % 12) + 48 );

            music+=music;

            cin >> w1;
            for( i=1; i<t; i++ ) {
                cin >> w2;
                trecho += ( (((mapa[w2]+12) - mapa[w1]) % 12) + 48 );
                w1 = w2;
            } 

            
            if( music.find(trecho)!=string::npos ) {
                cout << "S\n";
            } else {
                cout << "N\n";
            }
        }          
    }

    return 0;
}
