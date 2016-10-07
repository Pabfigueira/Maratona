#include <bits/stdc++.h> 

using namespace std;

vector< long int > vetor;

vector< long int > cost;


/*long int find( long int a ) { 
    return vetor[a] == a ? a : vetor[a] = find( vetor[a] );
}

void Union( long int a, long int b ) {
    vetor[ find(a) ] = find(b);    
}*/


long int find( long int a ) {
    if( vetor[a] == a ) {
        return a;
    } else {
        long int pai = vetor[a];
        
        vetor[a] = find( vetor[a] );
        
        cost[a] += cost[pai];

        return vetor[a];
    }
}


void Union( long int a, long int b ) {
    vetor[ find(a) ] = find(b);    
}

int main() {
    
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    long int n, m, a, b, c, la, lb, i;
    char op;

    while( cin >> n >> m && (n||m) ) {
        vetor.clear();
        vetor.resize(n);

        cost.clear();
        cost.resize(n,0);
    
        for( i=0; i<n; i++ ) {
            vetor[i] = i;
        }

        for( i=0; i<m; i++ ) {
            cin >> op >> a >> b;
            a--; b--;

            la = find(a);
            lb = find(b);

            if( op=='!' ) {
                cin >> c; 
                
                if( la!=lb ) {
                    Union(a,b);
                    cost[ la ] = (c - cost[a]) + cost[b];
                } 
            } else {
                if( la==lb ) {
                    cout << cost[a]-cost[b] << '\n';
                } else {
                    cout << "UNKNOWN\n";
                }
            }
        }
         
    }
    return 0;
}
