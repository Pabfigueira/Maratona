#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int part, budget, hotels, weeks, i, j, vaga;
    double price, cost; 
    while( cin >> part >> budget >> hotels >> weeks ) {
        
        price = numeric_limits<double>::max();
    
        for( i=0; i<hotels; i++ ) {
            cin >> cost;

            for( j=0; j<weeks; j++ ) {
                cin >> vaga;
                if( vaga>=part  && cost<price ) { 
                    price = cost;    
                }
            }
        }

        if( price*part > budget ) {
            cout << "stay home\n";
        } else {
            cout << price*part << '\n';
        }
    }     
    return 0;
}