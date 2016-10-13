#include <bits/stdc++.h>

using namespace std;

#define INF numeric_limits<int>::max()
#define NINF numeric_limits<int>::min()

vector<int> vetor;
vector<int> segTree;
bool maximo;

int query( int p, int i, int j, int e, int d ) {
    if( i>d || j<e ){
        if( !maximo )  return INF;
        else           return NINF;
    }
    if( e>=i && d<=j ) return segTree[p];
    
    int q1 = query( 2*p, i, j, e, (e+d)/2 );
    int q2 = query( (2*p)+1, i, j, 1+((e+d)/2), d );

    if( !maximo ) return min(q1,q2);
    else return max(q1,q2);
} 


void build( int p, int e, int d ) {
    if( e==d ) {
        segTree[p] = vetor[e];
    } else {
        build( 2*p, e, (e+d)/2 );
        build( (2*p)+1, 1 +((e+d)/2), d);
        if( !maximo ) 
            segTree[p] = min( segTree[2*p], segTree[(2*p)+1] );
        else
            segTree[p] = max( segTree[2*p], segTree[(2*p)+1] );
    }
} 

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int t, a, e, j, i, n, soma, k;
    string name;

    cin >> t; 
    
    vector< pair<int,string> > resp;


    for( a=0; a<t; a++ ) {
        cin >> e >> n >> j;
        resp.clear();
        resp.resize(e);
        for( i=0; i<e; i++ ) {
            cin >> name;

            vetor.clear();
            vetor.resize(n);

            segTree.clear();
            segTree.resize(4*n,INF);

            soma = 0;
            maximo = false;

            for( k=0; k<n; k++ ) {
                cin >> vetor[k];
            }

            build(1,0,n-1); 

            for( k=0; k<=n-j; k++ ) {
                soma += query(1,k,k+j-1,0,n-1);
            }
 
            maximo = true;

            segTree.clear();
            segTree.resize(4*n,NINF);
            build(1,0,n-1);
            for( k=0; k<=n-j; k++ ) {
                soma += query(1,k,k+j-1,0,n-1);
            }
            
            resp[i] = make_pair( soma*(-1), name );
        } 
        sort(resp.begin(),resp.end());
        cout << resp[0].second << " " << resp[0].first*(-1) << endl;
    }
    
    return 0;
}
