#include <bits/stdc++.h>

using namespace std;

int main() {
    char tipo, c;
    int n, a, linha, coluna, i, j;
    
    vector< pair<char, pair<int,int> > > vetor;

    vector< vector<int> > matriz;

    while( cin >> n ) {

        vetor.clear();
        vetor.resize(n);
      
        matriz.clear();
        matriz.resize(8,vector<int>(8,0));

        for( a=0; a<n; a++ ) {
            cin >> tipo >> c >> linha;
            linha--;
            coluna = (c-'a');
            vetor[a] = make_pair( tipo, make_pair(linha,coluna) );
            matriz[linha][coluna] = -1;
        }

        for( a=0; a<n; a++ ) {
            linha  = vetor[a].second.first;
            coluna = vetor[a].second.second;

            if( vetor[a].first == 'P' ) {
                if( linha-1>=0 && coluna-1>=0 ) {
                    if( matriz[linha-1][coluna-1] == 0 || matriz[linha-1][coluna-1] == 1) {
                        matriz[linha-1][coluna-1] = 1;
                    } else {
                        matriz[linha-1][coluna-1] = -2;
                    }
                }

                if( linha-1>=0 && coluna+1<8 ) {
                    if( matriz[linha-1][coluna+1] == 0 || matriz[linha-1][coluna+1] == 1) {
                        matriz[linha-1][coluna+1] = 1;
                    } else {
                        matriz[linha-1][coluna+1] = -2;
                    }
                }
            }
            if( vetor[a].first == 'T' || vetor[a].first == 'R') {
                
                i = linha+1;
                j = coluna;
                while( i<8 && matriz[i][j]!=-1 && matriz[i][j]!=-2 ){
                    matriz[i][j] = 1;
                    i++;
                }
                if( i<8 ) {
                    matriz[i][j] = -2;
                }


                i=linha-1;
                j=coluna;
                while( i>=0 && matriz[i][j]!=-1 && matriz[i][j]!=-2 ) {
                    matriz[i][j] = 1;
                    i--;
                }
                if( i>=0 ) {
                    matriz[i][j] = -2;
                }


                i=linha;
                j=coluna+1;
                while( j<8 && matriz[i][j]!=-1 && matriz[i][j]!=-2 ) {
                    matriz[i][j] = 1;
                    j++;
                }
                if( j<8 ){
                    matriz[i][j] = -2;
                }


                i=linha;
                j=coluna-1;
                while( j>=0 && matriz[i][j]!=-1 && matriz[i][j]!=-2 ) {
                    matriz[i][j] = 1;
                    j--;
                }
                if( j>=0 ) {
                    matriz[i][j] = -2;
                }


            }
            if( vetor[a].first == 'B' || vetor[a].first == 'R') {
            
                i = linha+1;
                j = coluna+1;
                while( i<8 && j<8 && matriz[i][j]!=-1 && matriz[i][j]!=-2 ) {
                    matriz[i][j] = 1;
                    i++;
                    j++;
                }
                if( i<8 && j<8 ) {
                    matriz[i][j] = -2;
                }


                i = linha-1;
                j = coluna-1;
                while( i>=0 && j>=0 && matriz[i][j]!=-1 && matriz[i][j]!=-2 ) {
                    matriz[i][j] = 1;
                    i--;
                    j--;
                }
                if( i>=0 && j>=0 ) {
                    matriz[i][j] = -2;
                }


                i = linha+1;
                j = coluna-1;
                while( i<8 && j>=0 && matriz[i][j]!=-1 && matriz[i][j]!=-2 ) {
                    matriz[i][j] = 1;
                    i++;
                    j--;
                }
                if( i<8 && j>=0 ) {
                    matriz[i][j] = -2;
                }


                i = linha-1;
                j = coluna+1;
                while( i>=0 && j<8 && matriz[i][j]!=-1 && matriz[i][j]!=-2 ) {
                    matriz[i][j] = 1;
                    i--;
                    j++;
                }
                if( i>=0 && j<8 ) {
                    matriz[i][j] = -2;
                }

            }
            if( vetor[a].first == 'W' ) {
                
                i = linha-1;
                j = coluna-1;
                if( i>=0 && j>=0 ) {
                    if( matriz[i][j]==0 || matriz[i][j]==1 ) {
                        matriz[i][j] = 1;
                    } else {
                        matriz[i][j] = -2;
                    }
                }

                i = linha-1;
                j = coluna;
                if( i>=0 ) {
                    if( matriz[i][j]==0 || matriz[i][j]==1 ) {
                        matriz[i][j] = 1;
                    } else {
                        matriz[i][j] = -2;
                    }
                }


                i = linha-1;
                j = coluna+1;
                if( i>=0 && coluna<8 ) {
                    if( matriz[i][j]==0 || matriz[i][j]==1 ) {
                        matriz[i][j] = 1;
                    } else {
                        matriz[i][j] = -2;
                    }
                }


                i = linha;
                j = coluna-1;
                if( j>=0 ) {
                    if( matriz[i][j]==0 || matriz[i][j]==1 ) {
                        matriz[i][j] = 1;
                    } else {
                        matriz[i][j] = -2;
                    }
                }


                i = linha;
                j = coluna+1;
                if( j<8 ) {
                    if( matriz[i][j]==0 || matriz[i][j]==1 ) {
                        matriz[i][j] = 1;
                    } else {
                        matriz[i][j] = -2;
                    }
                }


                i = linha+1;
                j = coluna-1;
                if( i<8 && j>=0 ) {
                    if( matriz[i][j]==0 || matriz[i][j]==1 ) {
                        matriz[i][j] = 1;
                    } else {
                        matriz[i][j] = -2;
                    }
                }


                i = linha+1;
                j = coluna;
                if( i<8 ) {
                    if( matriz[i][j]==0 || matriz[i][j]==1 ) {
                        matriz[i][j] = 1;
                    } else {
                        matriz[i][j] = -2;
                    }
                }


                i = linha+1;
                j = coluna+1;
                if( i<8 && j<8 ) {
                    if( matriz[i][j]==0 || matriz[i][j]==1 ) {
                        matriz[i][j] = 1;
                    } else {
                        matriz[i][j] = -2;
                    }
                }
            }  
        }
        
        cin >> tipo >> c >> linha;
        linha--;
        coluna = (c-'a');

        bool check = true;


        /*cout << coluna+1 << " " << linha+1 << endl;
        for( i=0;i<8;i++) {
            for( j=0;j<8;j++ ) {
                if( matriz[i][j] >= 0 ) cout << " ";
                cout << matriz[i][j] << " ";
            }
            cout << endl;
        }*/

        if( matriz[linha][coluna] == 0 || matriz[linha][coluna]==-1 ) {
            check = false;
        }

        i = linha-1;
        j = coluna-1;
        if( i>=0 && j>=0 ) {
            if( matriz[i][j]==0 || matriz[i][j]==-1 ) {
                check = false;
            }
        }
        
        i = linha-1;
        j = coluna;
        if( i>=0 ) {
            if( matriz[i][j]==0 || matriz[i][j]==-1 ) {
                check = false;
            }
        }


        i = linha-1;
        j = coluna+1;
        if( i>=0 && coluna<8 ) {
            if( matriz[i][j]==0 || matriz[i][j]==-1 ) {
               check = false;
            }
        }


        i = linha;
        j = coluna-1;
        if( j>=0 ) {
            if( matriz[i][j]==0 || matriz[i][j]==-1 ) {
                check = false;
            }
        }


        i = linha;
        j = coluna+1;
        if( j<8 ) {
            if( matriz[i][j]==0 || matriz[i][j]==-1 ) {
                check = false;
            }
        }


        i = linha+1;
        j = coluna-1;
        if( i<8 && j>=0 ) {
            if( matriz[i][j]==0 || matriz[i][j]==-1 ) {
                check = false;
            }
        }


        i = linha+1;
        j = coluna;
        if( i<8 ) {
            if( matriz[i][j]==0 || matriz[i][j]==-1 ) {
                check = false;
            }
        }


        i = linha+1;
        j = coluna+1;
        if( i<8 && j<8 ) {
            if( matriz[i][j]==0 || matriz[i][j]==-1 ) {
                check = false;
            }
        }
       
        if( check ) cout << "SIM\n";
        else cout << "NAO\n";
    }
    return 0;
}
