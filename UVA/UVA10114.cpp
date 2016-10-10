#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    float a, b, c, d, car, loan, i, indice, tax, payment;

    map<int,float> mapa;
    map<int,float>::iterator it;

    while( cin >> a >> b >> c >> d && (a>=0) ) {
        car = c+b;
        loan = c;

        mapa.clear();
        
        for( i=0; i<d; i++ ) {
            cin >> indice >> tax;
            mapa[indice] = tax;
        }

        car -= (car * mapa[0]);

        i = 1;

        
        payment = c/a;

        while( loan > car ) {
            loan -= payment;

            it = mapa.upper_bound(i);
            it--;

            car -= (car * (it->second));
            i++;

        }

        if( i==1 ) cout << "0 months\n";
        else if( i==2 ) cout << "1 month\n";
        else cout << i-1 << " months\n";
    }
    return 0;
}
