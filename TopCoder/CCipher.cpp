#include <bits/stdc++.h>

using namespace std;

class CCipher {
    public:
        string decode(string word, int shift) {
            int i;
            for( i=0; i<word.size(); i++ ) {
                word[i] -= 'A';
                word[i] -= shift;
                if( word[i] < 0 ) word[i] = (word[i] + 26)%26;
                word[i] += 'A';
            }
            return word;
        }
};
