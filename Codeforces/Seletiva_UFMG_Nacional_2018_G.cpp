#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

bool init( string word ) {
    string one = "Fala meu consagrado";
    
    if( word.size() < one.size() ) return false;

    for( ll i=0; i<(ll)one.size(); i++ ) {
        if( word[i]!=one[i] ) return false;    
    }
    return true;
}

bool end( string word ) {
    string one = "Aquele abraco meu chegado";
    
    if( word.size() < one.size() ) return false;

    ll j = word.size()-1;

    for( ll i=one.size()-1; i>=0; i--, j--) {
        if( word[j]!=one[i] ) return false;    
    }
    return true;
}

string ko( string word ) {
    ll i;
    for( i=0; i<(ll)word.size(); i++ ) {
        
        if( word[i]=='p' ) word[i] = 'v';
        else if( word[i]=='e' ) word[i] = 'i';
        else if( word[i]=='b' ) word[i] = 't';
        else if( word[i]=='l' ) word[i] = 'a';
        else if( word[i]=='o' ) word[i] = 'r';

        else if( word[i]=='v' ) word[i] = 'p';
        else if( word[i]=='i' ) word[i] = 'e';
        else if( word[i]=='t' ) word[i] = 'b';
        else if( word[i]=='a' ) word[i] = 'l';
        else if( word[i]=='r' ) word[i] = 'o';


        else if( word[i]=='P' ) word[i] = 'V';
        else if( word[i]=='E' ) word[i] = 'I';
        else if( word[i]=='B' ) word[i] = 'T';
        else if( word[i]=='L' ) word[i] = 'A';
        else if( word[i]=='O' ) word[i] = 'R';

        else if( word[i]=='V' ) word[i] = 'P';
        else if( word[i]=='I' ) word[i] = 'E';
        else if( word[i]=='T' ) word[i] = 'B';
        else if( word[i]=='A' ) word[i] = 'L';
        else if( word[i]=='R' ) word[i] = 'O';
    }
    return word;
}

string rot( string word ) {
    ll i;
    for( i=0; i<(ll)word.size(); i++ ) {
        if( word[i]>='a' and word[i]<='z' ) {
            word[i] = ((word[i] - 'a' + 9)%26);
            word[i] += 'a';
        } else if(word[i]>='A' and word[i]<='Z') {
            word[i] = ((word[i] - 'A' + 9)%26);
            word[i] += 'A';
        } 
    }
    return word;
}


int main() {

    ios_base::sync_with_stdio(false);

    ll n, i;

    cin >> n;

    vector<string> text(n);

    getline(cin,text[0]);

    for( i=0; i<n; i++ ) {
        getline(cin,text[i]);
    } 

    if( init( rot(text[0]) ) or end( rot(text[n-1]) ) ) {

        for( i=0; i<n; i++ ) {
            cout << rot(text[i]) << endl;
        }

    } else if( init( ko(text[0]) ) or end( ko(text[n-1]) ) ) {

        for( i=0; i<n; i++ ) {
            cout << ko(text[i]) << endl;
        }

    } else {
        cout << "Biro-Biro Astuto" << endl;
    }
    
    return 0;
}
