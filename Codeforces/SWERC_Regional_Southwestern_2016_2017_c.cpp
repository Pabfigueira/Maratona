#include <bits/stdc++.h> 

using namespace std;

int main() {
    
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int d, r, t, soma, i, cont=0;

    cin >> d >> r >> t;

    vector<int> a;
    vector<int> b;
    vector<int>::iterator it, ita;
        
    i = 4;
    soma = 0;
    while( soma < 1000 ) {
        soma += i;
        i++;
        a.push_back(soma);
    }
    
    i=3;
    soma = 0;
    while( soma < 1000 ) {
        soma += i;
        i++;
        b.push_back(soma);
    }


    bool valid = false;

    while( !valid ) {
        it = upper_bound( a.begin(), a.end(), r );
        ita = upper_bound( b.begin(), b.end(), t );
        it--; ita--;

        if( *it==r && *ita==t && 
                            abs(distance(a.begin(),it) - distance(b.begin(),ita)) == d-1 ) {
            valid = true;
        } else if( r==*it ) {
            cont += 4;
            t += 4;
            r -= 4;
        } else {
            cont += (r - *it);
            t += (r - *it);
            r  = *it;
        }
    }

    cout << cont << endl;

    return 0;
}
