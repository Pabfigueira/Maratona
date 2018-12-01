#include<bits/stdc++.h>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);

    string s, t, mine;
    int len, goOne, i;

    getline(cin,s);
    getline(cin,t);

    len = s.size();

    mine.resize(len);

    goOne = 0;
    i = len-1;
    while( i>=0 ) {
        if( goOne == 1 ) {
            if( goOne + (s[i]-'a') >= 26 ) {
                mine[i] = 'a';
            } else {
                mine[i] = (char)(s[i]+1);
                i--;
                break;
            }
        } else {
            if( (s[i]-'a') + 1 >= 26 ) {
                goOne = 1;
                mine[i] = 'a';
            } else {
                mine[i] = (char)(s[i]+ 1);
                i--;
                break;
            }
        }
        i--;
    }
    while( i>=0 ) {
        mine[i] = s[i];
        i--;
    }
    
    if( mine.compare(t)==0 ) cout << "No such string\n";
    else cout << mine << endl;

    return 0;
}
