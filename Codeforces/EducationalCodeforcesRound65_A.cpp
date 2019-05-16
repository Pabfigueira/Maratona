#include<bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    int t, n, i;
    bool good;
    string word;
    cin >> t; 
    while(t--) {
        cin >> n >> word;
        good = false;
        if(n<11) {
            cout << "NO\n";
        } else {
            for(i=0; i<=n-11; i++) {
                if(word[i]=='8') good = true;        
            }
            if(good) cout << "YES\n";
            else cout << "NO\n";
        }
    }
    return 0;
}
