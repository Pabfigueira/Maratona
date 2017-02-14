#include <bits/stdc++.h>

using namespace std;

int main() {
    int a,b,c,d,e,i,j,k,l,resp;
    vector <int> vetor(5);
    while ( cin >> vetor[0] >> vetor[1] >> vetor[2] >> vetor[3] >> vetor[4] && (vetor[0]||vetor[1]||vetor[2]||vetor[3]||vetor[4]) ) {
        bool statement = false;
        resp = 0;
        sort(vetor.begin(),vetor.end());
        do {
            a = vetor[0];   
            b = vetor[1];
            c = vetor[2];   
            d = vetor[3];
            e = vetor[4];
            
            for(i=0;i<3;i++) {
                for(j=0;j<3;j++) {
                    for(k=0;k<3;k++) {
                        for(l=0;l<3;l++){
                    
                            if(i==0) { resp = a+b; } else if(i==1) { resp = a-b; } else { resp = a*b; }

                            if(j==0) { resp = resp+c; } else if(j==1) { resp = resp-c; } else { resp = resp*c; }
         
                            if(k==0) { resp = resp+d; } else if(k==1) { resp = resp-d; } else { resp = resp*d; }
  
                            if(l==0) { resp = resp+e; } else if(l==1) { resp = resp-e; } else { resp = resp*e; }

                            if(resp==23) { statement = true; }
                        }
                    }
                } 
            }

        } while( next_permutation(vetor.begin(),vetor.end()) );
        if(statement) { cout << "Possible\n"; }
        else { cout << "Impossible\n"; }              
    }
    return 0;
}
