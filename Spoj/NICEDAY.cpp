#include <bits/stdc++.h> 

using namespace std;

#define INF  numeric_limits<int>::max()
#define NINF numeric_limits<int>::min()

vector<int> segTree;

vector< pair<int, pair<int,int> > > vetor;

void update( int p, int e, int d, int idx, int value ) {
    if( idx>d  || idx<e ) return;

    if( idx==e && idx==d ) {
        segTree[p] = value; 
        return;
    }

    update( 2*p, e, (e+d)/2, idx, value);
    update( (2*p)+1, 1+((e+d)/2), d, idx, value);
    
    segTree[p] = min( segTree[2*p], segTree[(2*p)+1]);
}

int query( int p, int i, int j, int e, int d ) {
    if( i>d || j<e ) {
        return INF;
    }

    if( e>=i && d<=j ) return segTree[p];

    int q1 = query( 2*p, i, j, e, (e+d)/2 );
    int q2 = query( (2*p)+1, i, j, 1+((e+d)/2), d );
    
    return min(q1,q2);
}


int main() {
    
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int t, a, n, b, one, two, three, qt;

    cin >> t;

    for( a=0; a<t; a++ ) {
        cin >> n;

        qt = n;

        vetor.clear();
        vetor.resize(n);

        for( b=0; b<n; b++ ) {
            cin >> one >> two >> three;
            vetor[b] = make_pair( one, make_pair(two,three) );
        }

        sort(vetor.begin(),vetor.end());

        segTree.clear();
        segTree.resize(n*4,INF);

        for( b=0; b<n; b++ ) {
            update(1, 0, n-1, vetor[b].second.first, vetor[b].second.second);
            if( query(1,0,vetor[b].second.first,0,n-1) < vetor[b].second.second ) qt--; 
        }
        cout << qt << '\n'; 
    }
    return 0;
}


