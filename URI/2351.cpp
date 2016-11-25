#include <bits/stdc++.h>
#define buff ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

using namespace std;

int main() {
    buff;
    int n, k, i, num, cont, soma, menos;
    
    priority_queue<int> pilha;

    cin >> n >> k;

    cont = 0;
    soma = 0;
    menos = 0;
    
    for( i=0; i<n; i++ ) {
        cin >> num;
        soma += num;
        if( cont == k ) {
            pilha.push(-num);
            menos += num;
            cont = 0;
        } else { 
            if( pilha.size() > 0 && num > -pilha.top() ){
                menos += pilha.top();
                pilha.pop();
                pilha.push(-num);
                menos += num;
            } 
            cont++; 
        }  
    }
    cout << soma - menos << endl; 
    return 0;
}
