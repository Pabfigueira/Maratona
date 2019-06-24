#include<bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);    

    bool remove;
    int n, m, i, j, cntRemove;
    cin >> n >> m;
    vector<vector<char>> matrix(n+2,vector<char>(m+2));
    vector<vector<int>> isDiff(n+2,vector<int>(m+2,0));

    for(i=1; i<=n; i++) {
        for(j=1; j<=m; j++) {
            cin >> matrix[i][j];
        }
    }

    cntRemove = 0;
    for(j=1; j<=m; j++) {
        remove = false;
        for(i=2; i<=n and !remove; i++) {
            if(isDiff[i][j-1]==0) {
                if(matrix[i][j]<matrix[i-1][j]) remove=true;
                else if(matrix[i][j]==matrix[i-1][j]) isDiff[i][j] = 0;
                else isDiff[i][j] = 1;
            } else {
                isDiff[i][j] = 1;
            }                                   
        }
        if(remove) {
            for(i=0; i<=n; i++) {
                isDiff[i][j] = isDiff[i][j-1];        
            }
            cntRemove++;
        }
    } 
    cout << cntRemove << endl;
    return 0;
}
