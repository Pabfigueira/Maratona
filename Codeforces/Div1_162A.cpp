#include <bits/stdc++.h>

using namespace std;

char word[1000003];

vector<int> lefta(1000003);

int main() {

    scanf("%s",word);

    int i, j, unsize;

    unsize = strlen(word);

    j = 0;
    for( i=0; i<unsize; i++ ) {
        if( word[i]=='l' ) {
            lefta[j] = i+1;
            j++;
        }
        else printf("%d\n",i+1);
    }

    for( i=j-1; i>=0; i-- ) {
        printf("%d\n",lefta[i]);
    }

    return 0;
}
