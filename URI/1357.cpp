#include <bits/stdc++.h>

using namespace std; 

int main() {
    //ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    int d, i, tam, j;
    char op, num;
    string word;
    map<char, string> l1,l2,l3;
    map<string, char> td;
    vector<char> vetor;   

 
    l1['1'] = "*."; l2['1'] = ".."; l3['1'] = "..";
    
    l1['2'] = "*."; l2['2'] = "*."; l3['2'] = "..";
    
    l1['3'] = "**"; l2['3'] = ".."; l3['3'] = "..";
    
    l1['4'] = "**"; l2['4'] = ".*"; l3['4'] = "..";
    
    l1['5'] = "*."; l2['5'] = ".*"; l3['5'] = "..";
    
    l1['6'] = "**"; l2['6'] = "*."; l3['6'] = "..";
    
    l1['7'] = "**"; l2['7'] = "**"; l3['7'] = "..";
    
    l1['8'] = "*."; l2['8'] = "**"; l3['8'] = "..";
    
    l1['9'] = ".*"; l2['9'] = "*."; l3['9'] = "..";
    
    l1['0'] = ".*"; l2['0'] = "**"; l3['0'] = "..";
    

    td["*....."] = '1';
    td["*.*..."] = '2';
    td["**...."] = '3';
    td["**.*.."] = '4';
    td["*..*.."] = '5';
    td["***..."] = '6';
    td["****.."] = '7';
    td["*.**.."] = '8';
    td[".**..."] = '9';
    td[".***.."] = '0';

    while( cin >> d && d ) {
        cin >> op;
        vetor.clear();

        vetor.resize(d);

        if( op == 'S' ) {
            for(i=0;i<d;i++) {
                cin >> num;
                vetor[i] = num;
            }

            cout << l1[vetor[0]];
            for( i=1; i<d; i++ ) {
                cout << " " << l1[vetor[i]];
            }
            cout << endl;


            cout << l2[vetor[0]];
            for( i=1; i<d; i++ ) {
                cout << " " << l2[vetor[i]];
            }
            cout << endl;

            cout << l3[vetor[0]];
            for( i=1; i<d; i++ ) {
                cout << " " << l3[vetor[i]];
            }
            cout << endl;
                
        } else {
            tam = (2*d)+(d-1);
            vector< vector<char> > matriz (3, vector<char>(tam));

            //cout << "\n\n-------------\n";
            for( i=0; i<3; i++ ) {
                getline(cin,word);
                for( j=0; j<tam; j++ ) { 
                    scanf("%c",&matriz[i][j]);
                    //cout << matriz[i][j] << " ";         
                }
                //cout << endl;
            }
            //cout << "-------------";
            
                        

            for( j=0; j<tam; j+=3 ) {
                word.clear();
                word+=matriz[0][j]; word+=matriz[0][j+1];
                word+=matriz[1][j]; word+=matriz[1][j+1];
                word+=matriz[2][j]; word+=matriz[2][j+1];
                cout << td[word];
            } 
            cout << endl;
        }         
    }
    return 0;
}
