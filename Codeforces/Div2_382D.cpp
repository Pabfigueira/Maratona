#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define MAX 10000
#define BAG 1000
#define INF numeric_limits<int>::max()

vector<ll> vetor(MAX+5,-1);
vector<ll> listOfPrimes;

void crivo() {
    for( ll i=2; i<=MAX; i++ ) {
        if( vetor[i]==-1 ) {
            vetor[i] = 1;
            listOfPrimes.push_back(i);
            ll multi = 2;
            while( multi*i <= MAX ) {
                vetor[multi*i] = 0;
                multi++;            
            }
        } 
    }        
}

bool isPrime( ll number ) {
    ll meio = sqrt(number) + 1;

    for( ll i=2; i<=meio; i++ ) {
        if( number%i==0 ) return false;
    }
    return true;
}


int main() {
    crivo();

    vector<ll> dp(BAG+5,INF);
    dp[0] = 0;

    ll i, j;

    for( i=2; i<=BAG; i++ ) {
        for( j=0; j<(ll)listOfPrimes.size(); j++ ) {
            if( i >= listOfPrimes[j] ) {
                dp[i] = min(dp[i],dp[i - listOfPrimes[j]] + 1);
            }
        }
    }


    ll number, nextPrime, distance;

    scanf("%lld",&number);

    if( isPrime(number) or number==2 ) { 
        printf("1\n");        
    } else { 
        if( number%2==0 ) printf("2\n");
        else {
            nextPrime = number-2;
            while( !isPrime(nextPrime) ) nextPrime--;

            distance = number - nextPrime;
        
            printf("%lld\n",1+dp[distance]); 
        }
    }

    return 0;
}
