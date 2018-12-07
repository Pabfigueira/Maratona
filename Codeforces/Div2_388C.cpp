#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ll n, i, rep, dem, qtdR, qtdD;
    char thief;    
    queue<char> next;    

    rep = dem = qtdR = qtdD = 0;

    scanf("%lld",&n);


    scanf("%c",&thief);
    for( i=0; i<n; i++ ) {
        scanf("%c",&thief);
        next.push(thief);
        if( thief == 'D' ) qtdD++;
        else qtdR++;
    }

    while( qtdR > 0 and qtdD > 0 ) {
        thief = next.front();
        next.pop();

        if( thief == 'D' and dem<0 ) {
            dem++;
            continue;
        }      

        if( thief == 'R' and rep<0 ) {
            rep++;
            continue;
        }

        if( thief == 'D' ) {
            rep--;
            qtdR--;
            next.push(thief); 
        } else {
            dem--;
            qtdD--;
            next.push(thief);
        }
    }
    if( qtdR > 0 ) printf("R\n");
    else printf("D\n");
    return 0;
}
