#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {

    ll n, q, i, contador, readed, a, b;
    
    scanf("%lld%lld",&n,&q);

    vector<ll> app(n+1,0);
    queue<ll> fila;
    vector<ll> falta(n+1,0);

    contador = 0;
    readed   = 0;

    for( i=0; i<q; i++ ) {
        scanf("%lld%lld",&a,&b);
        if( a==1 ) {
            contador++;
            app[b]++;
            fila.push(b);
        } else if( a==2 ) { 
            contador -= app[b];
            falta[b] += app[b];
            app[b] = 0;
        } else {
            if( b > readed ) {
                b-=readed;
                while( b>0 ) {
                    a = fila.front();
                    fila.pop();
                    if( falta[a] > 0 ) {
                        falta[a]--;
                        b--;
                        readed++;
                    } else {
                        app[a]--;
                        readed++;
                        contador--;
                        b--;
                    }
                }
            }    
        }
        printf("%lld\n",contador);
    }
    return 0;
}
