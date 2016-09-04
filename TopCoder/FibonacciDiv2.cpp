#include <bits/stdc++.h>
#define MAX 1000000

using namespace std;

class FibonacciDiv2 {
    public:
        int find(int n);
};

int FibonacciDiv2::find ( int n ) {
    
    vector<unsigned long long int> fib(MAX+1);
    vector<unsigned long long int>::iterator it, ita;

    unsigned long long int i;

    fib[0] = 0;
    fib[1] = 1;
    
    for( i=2; i<=MAX; i++ ) {
        fib[i] = fib[i-1] + fib[i-2];
    }

    sort(fib.begin(),fib.end());

    it = lower_bound(fib.begin(), fib.end(), n);
    ita = upper_bound(fib.begin(), fib.end(), n);

    /*cout << endl;
    for( i=0;i<20;i++ ) {
        cout << fib[i] << " ";
    }
    cout << endl;*/

    if( (*it) == n ) {
        return 0;
    } else {
        it--; 
        return min(n-(*it), (*ita)-n);
    }
}



int main() {

    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    FibonacciDiv2 minha;
    int n;
    while(cin >> n ) {
        cout << minha.find(n) << endl;
    }
    return 0;  
}
