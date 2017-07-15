#include <bits/stdc++.h>

using namespace std;

#define sc(x) scanf("%d", &x)
#define sc2(a,b) scanf("%d%d",&a,&b)
#define sc3(a,b,c) scanf("%d%d%d", &a,&b,&c)
#define scs(a) scanf("%s", a)
#define pri(x) printf("%d\n",x)
#define prie(x) printf("%d ",x)
#define mp make_pair
#define pb push_back
#define BUFF ios::sync_with_stdio(false);
#define f first
#define s second

typedef long long int ll;
typedef long double ld;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vector<ii> > vvii;

const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3fll;
const ld pi = acos(-1);
const int MOD = 1e9 + 7;

map<string,bool> mapaList;
map<string,bool>::iterator it;

bool isElement( string word );

bool isAtom( string word ) {
    if( word.compare("{")==0 || word.compare(",")==0 || word.compare("}")==0 ) return true;
    return false;
}

bool isList( string word ) {
    if( word.size()==0 ) return false;

    it = mapaList.find(word);
    if( it!=mapaList.end() ) return it->second;

    string aux,aux2;
    aux2 = word;
    aux2.erase(aux2.begin());
    int i = 0, tam = word.size();

    if( isElement(word) ) return mapaList[word] = true;

    for( i=0; i<tam; i++ ) {
        if( word[i]==',' ) {
            if( isElement(aux) && isList(aux2) ) return mapaList[word] = true;
        }
        aux += word[i];
        if( aux2.size()!=0 ) {
            aux2.erase(aux2.begin());
        }
    } 
    return mapaList[word] = false;
}

bool isElementList( string word ) {
    if( word.size()==0 || isList(word) ) return true;
    return false;
}


bool isSet( string word ) {
    if( word.size() < 2 ) {
        return false;
    }
    string aux;
    aux = word;
    aux.erase(aux.begin());
    aux.erase(aux.begin()+aux.size()-1);
    if( word[0]!='{' || word[word.size()-1]!='}' || !isElementList(aux) ) return false;
    return true;
}

bool isElement( string word ) {
    if( isAtom(word) || isSet( word ) ) return true;
    return false;
}

int main() {
    int n, i;
    string word;
    
    cin >> n;
    getline(cin,word);
    
    for( i=0; i<n; i++ ) {
        mapaList.clear();
        getline(cin,word);
        if( isSet(word) ) cout << "Word #" << i+1 << ": Set\n";
        else cout << "Word #" << i+1 << ": No Set\n";
    }
    return 0;
} 
