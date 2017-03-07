#include <bits/stdc++.h>

using namespace std;

#define sc(a) scanf("%d", &a)
#define sc2(a, b) scanf("%d%d", &a, &b)
#define sc3(a, b, c) scanf("%d%d%d", &a, &b, &c)
#define scs(a) scanf("%s", a)
#define pri(x) printf("%d\n", x)
#define prie(x) printf("%d ", x)
#define mp make_pair
#define pb push_back
#define BUFF ios::sync_with_stdio(false);
#define db(x) cerr << #x << " == " << x << endl
#define dbs(x) cerr << x << endl
#define ler freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#define imprime(x, Y)                              \
  for (int X = 0; X < Y; X++) cerr << x[X] << " "; \
  cerr << endl;
typedef long long int ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vector<ii> > vvii;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const ld pi = acos(-1);
const int MOD = 1e9 + 7;
bool isPalindrome( string word ) {
    return ( word == string(word.rbegin(), word.rend()) );
}


bool isMirror(string word) {
    int i, j, tam;
    tam = word.size();

    for( i=0; i<tam; i++ ) {
        if( word[i]!='A' && word[i]!='E' && word[i]!='H' &&
            word[i]!='I' && word[i]!='J' && word[i]!='L' &&
            word[i]!='M' && word[i]!='O' && word[i]!='S' &&
            word[i]!='T' && word[i]!='U' && word[i]!='V' &&
            word[i]!='W' && word[i]!='X' && word[i]!='Y' &&
            word[i]!='Z' && word[i]!='1' && word[i]!='2' &&
            word[i]!='3' && word[i]!='5' && word[i]!='8' ) return false;
    }

    i = 0; j=tam-1;
    while( i<j ) {
        if( word[i]=='A' && word[j]!='A' ) return false;
        if( word[i]=='E' && word[j]!='3' ) return false;
        if( word[i]=='H' && word[j]!='H' ) return false;
        if( word[i]=='I' && word[j]!='I' ) return false;
        if( word[i]=='J' && word[j]!='L' ) return false;
        if( word[i]=='L' && word[j]!='J' ) return false;
        if( word[i]=='M' && word[j]!='M' ) return false;
        if( word[i]=='O' && word[j]!='O' ) return false;
        if( word[i]=='S' && word[j]!='2' ) return false;
        if( word[i]=='T' && word[j]!='T' ) return false;
        if( word[i]=='U' && word[j]!='U' ) return false;
        if( word[i]=='V' && word[j]!='V' ) return false;
        if( word[i]=='W' && word[j]!='W' ) return false;
        if( word[i]=='X' && word[j]!='X' ) return false;
        if( word[i]=='Y' && word[j]!='Y' ) return false;
        if( word[i]=='Z' && word[j]!='5' ) return false;
        if( word[i]=='1' && word[j]!='1' ) return false;
        if( word[i]=='2' && word[j]!='S' ) return false;
        if( word[i]=='3' && word[j]!='E' ) return false;
        if( word[i]=='5' && word[j]!='Z' ) return false;
        if( word[i]=='8' && word[j]!='8' ) return false;
        i++; j--;
    }
    return true;
}



int main() {

    string word;

    while( getline(cin,word) ) {
        if( isPalindrome(word) ) {
            if( isMirror(word) ) cout << word << " -- is a mirrored palindrome.\n";
            else cout << word << " -- is a regular palindrome.\n";
        } else {
            if( isMirror(word) ) cout << word << " -- is a mirrored string.\n";
            else cout << word << " -- is not a palindrome.\n";

        }
        cout << endl;
    }
    return 0;
}
