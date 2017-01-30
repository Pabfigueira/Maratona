#include <bits/stdc++.h> 
#define EPS 1e-10

using namespace std;

int main() {
    
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);


    long double a, b;

    unsigned long long int c; 

    cin >> a >> b;
    a+=EPS;

    c = floor(a/b);    

    cout << c << endl; 
    
    return 0;
}
