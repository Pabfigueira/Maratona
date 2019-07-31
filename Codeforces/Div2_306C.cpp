#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

bool ItsPossibleZero(string word) {
    ll i, n;
    n = word.size();
    for(i=n-1; i>=0; i--) {
        if(word[i]=='0') {
            return true;
        }
    }
    return false;
}

bool ItsPossible(string word, vector<char> arr) {
    ll i, j;
    i = word.size()-1; 
    j = arr.size()-1;
    
    while(i>=0) {
        if(word[i] == arr[j]) {
            j--;
            if(j==-1) return true;
        }
        i--;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);

    ll i, j, k;
    set<vector<char>> divisible;
    set<vector<char>>::iterator it;
    vector<char> arr;
    for(i=0; i<=9; i++) {
        for(j=0; j<=9; j++) {
            for(k=0; k<=9; k++) {
                if(((i*100)+(j*10)+k)%8==0 and i+j+k!=0) {
                    arr.clear();
                    if(i!=0) {
                        arr.push_back(i+'0');
                        arr.push_back(j+'0');
                    } else if(j!=0) {
                        arr.push_back(j+'0');
                    } 
                    arr.push_back(k+'0');
                    divisible.insert(arr);
                }
            }
        }
    }

    string word;
    cin >> word;
    if(ItsPossibleZero(word)) {
        cout << "YES\n";
        cout << "0\n";
        return 0; 
    }
    for(it=divisible.begin(); it!=divisible.end(); ++it) {
        if(ItsPossible(word,*it)) {
            cout << "YES\n";
            for(i=0; i<(ll)(*it).size(); i++) {
                cout << (*it)[i];
            }
            cout << endl;
            return 0;
        }    
    }
    cout << "NO\n";
    return 0;
}
