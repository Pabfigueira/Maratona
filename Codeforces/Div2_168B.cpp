#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> myleft;
vector<vector<int>> myright;
vector<vector<int>> myup;
vector<vector<int>> mydown;

bool reach(pair<int,int> one, pair<int,int> two) {  
    if(one.second > two.second) return reach(two,one);
    
    int diffC, diffL;
    diffC = two.second-one.second+1;
    if(one.first <= two.first) {
        diffL = two.first-one.first+1;
        if(myleft[two.first][two.second]>=diffC and myup[one.first][one.second]>=diffL) return true;
        if(myright[one.first][one.second]>=diffC and mydown[two.first][two.second]>=diffL) return true;
        return false;        
    } else {
        diffL = one.first-two.first+1;
        if(myleft[two.first][two.second]>=diffC and mydown[one.first][one.second]>=diffL) return true;
        if(myright[one.first][one.second]>=diffC and myup[two.first][two.second]>=diffL) return true;
        return false; 
    }
}

void printMatrix(vector<vector<int>> matrix, int n, int m) {
    int i, j;
    for(i=0; i<n; i++) {
        for(j=0; j<m; j++) {
            cout << matrix[i][j];
        }
        cout << endl;
    }
}

int main() {
    int n, m, i, j;
    char letter;

    scanf("%d%d",&n,&m);
    
    myleft.resize(n,vector<int>(m,0));
    myright.resize(n,vector<int>(m,0));
    myup.resize(n,vector<int>(m,0));
    mydown.resize(n,vector<int>(m,0));
    vector<pair<int,int>> blackPositions;
    
    for(i=0; i<n; i++) {
        scanf("%c",&letter);
        for(j=0; j<m; j++) {
            scanf("%c",&letter);
            if(letter=='B') {
                blackPositions.push_back(make_pair(i,j));
                myleft[i][j] = 1;
                myright[i][j] = 1;
                mydown[i][j] = 1;
                myup[i][j] = 1;
                if(j>0)   myleft[i][j]  += myleft[i][j-1];
                if(i>0)   mydown[i][j]  += mydown[i-1][j];
            }
        }
    }
    for(i=n-1; i>=0; i--) {
        for(j=m-1; j>=0; j--) {
            if(myright[i][j]==1 and j<m-1) myright[i][j] += myright[i][j+1];
            if(myup[i][j]==1 and i<n-1) myup[i][j] += myup[i+1][j];
        }
    }
    
    for(i=0; i<(int)blackPositions.size(); i++) {
        for(j=i+1; j<(int)blackPositions.size(); j++) {
            if(!reach(blackPositions[i],blackPositions[j])) {
                printf("NO\n");
                return 0;
            }
        }
    }
    
    printf("YES\n");
    return 0;
}
