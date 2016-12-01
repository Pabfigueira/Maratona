#include <bits/stdc++.h> 
#define MAX 1000001

using namespace std;

int main() {
    
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    

    bitset<MAX> bs;
    set<int>primos;

    int limite;
    
    bs.reset();
    bs.flip();

    limite = (int)sqrt(MAX);

    for( int i=2; i<=limite; i++ ) {
        if( bs.test((size_t)i)) {
            for( int j = i*i; j<MAX; j+=i )
                bs.set((size_t)j,false);
        }
    }

    for( int i=2; i<MAX; i++ ) {
        if( bs.test((size_t)i)){
            primos.insert(i);
        }
    }


    long long int a, q, x, y;
    
    cin >> q;
    
    vector<int>qtd(MAX+1);
    
    qtd[0] = 0;
    qtd[1] = 0;

    for( a=2; a<=MAX; a++ ) {
        qtd[a] = qtd[a-1];
        if( primos.find(a)!=primos.end() ) {
            if( primos.find(a+2)!=primos.end() || 
                primos.find(a-2)!=primos.end() ) {
                qtd[a]++;
            }
        }
    }

    for( a=0; a<q; a++ ) {
        cin >> x >> y;

        if( x > y ) swap(x,y);
        
        cout << (qtd[y] - qtd[x - 1]) << endl;
    }
    return 0;
}
