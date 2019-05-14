#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ll n, i, j, h, sum, maxOne, maxTwo; 
    pair<ll,ll> posOne;
    pair<ll,ll> posTwo;

    scanf("%lld",&n);
    vector<vector<ll>> matrix(n,vector<ll>(n));
    vector<vector<ll>> diag1(n,vector<ll>(n,0));
    vector<vector<ll>> diag2(n,vector<ll>(n,0));

    for(i=0; i<n; i++) {
        for(j=0; j<n; j++) {
            scanf("%lld",&matrix[i][j]);
        }
    }
    
    // Filling diag1
    for(h=0; h<n; h++) {
        j=0;
        i=h;
        sum = 0;
        while(j<n and i>=0) {
            sum += matrix[i][j];
            j++; i--;    
        }
        i=h;
        j=0;
        while(j<n and i>=0) {
            diag1[i][j] = sum;
            j++; i--;
        }
    }
    for(h=1; h<n; h++) {
        i=n-1;
        j=h;
        sum = 0;
        while(j<n and i>=0) {
            sum += matrix[i][j];
            j++; i--;
        }
        i=n-1;
        j=h;
        while(j<n and i>=0) {
            diag1[i][j] = sum;
            j++; i--;
        }
    }

    // Filling diag2
    for(h=0; h<n; h++) {
        j=n-1;
        i=h;
        sum = 0;
        while(i>=0 and j>=0) {
            sum += matrix[i][j];
            i--; j--;
        }
        j=n-1;
        i=h;
        while(i>=0 and j>=0) {
            diag2[i][j] = sum;
            i--; j--;
        }
    }
    for(h=n-2; h>=0; h--) {
        i=n-1;
        j=h;
        sum = 0;
        while(i>=0 and j>=0) {
            sum += matrix[i][j];
            i--; j--;
        }
        i=n-1;
        j=h;
        while(i>=0 and j>=0) {
            diag2[i][j] = sum;
            i--; j--;
        }
    }
    
    // searching result   
    posOne.first = 0;
    posOne.second = 0;
    posTwo.first = 0;
    posTwo.second = 1;
    maxOne = diag1[0][0]+diag2[0][0]-matrix[0][0];
    maxTwo = diag1[0][1]+diag2[0][1]-matrix[0][1];     

    for(i=0; i<n; i++) {
        for(j=0; j<n; j++) {
            h = diag1[i][j] + diag2[i][j]-matrix[i][j];
            if(i%2 != j%2) {
                if(h>maxOne) {
                    maxOne = h;
                    posOne.first = i;
                    posOne.second = j;    
                }
            } else {
                if(h>maxTwo) {
                    maxTwo = h;
                    posTwo.first = i;
                    posTwo.second = j;
                }
            }
        }
    }

    printf("%lld\n",maxOne+maxTwo);
    printf("%lld %lld %lld %lld\n",posOne.first+1,posOne.second+1,posTwo.first+1,posTwo.second+1);
    return 0;
}
