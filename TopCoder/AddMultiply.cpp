#include <bits/stdc++.h>

using namespace std;


class AddMultiply {
    public:
        vector<int> makeExpression( int y ) {
            int a, b, c;
    
            vector<int> vetor(3);

            for( a=-1000; a<=1000; a++ ) {
                for( b=-1000; b<=1000; b++ ) {
                    if( a!=1 && a!=0 && b!=0 && b!=1 ) {
                        c = y - (a*b);
                        if( c>=-1000 && c<=1000 && c!=0 && c!=1 ) {
                            vetor[0] = a;
                            vetor[1] = b;
                            vetor[2] = c;
                            return vetor;
                        }
                    }
                }
            }
        }
};


int main() {
    AddMultiply func;
    int n;
    vector<int> vetor;
    scanf("%d",&n);
    vetor = func.makeExpression(n);
    cout << vetor[0] << " " << vetor[1] << " " << vetor[2] << endl;
    return 0;
}
