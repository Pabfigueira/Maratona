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

void solve( string word ) {
    ll i, tam = word.size();

    vector<int> vetor(tam, 0);

    for( i=0; i<tam; i++ ) {
        if( word[i]>='A' && word[i]<='Z' ) {
            vetor[i] = 1;
        }
        word[i] = tolower(word[i]);
    }

    if( tam%2!=0 ) {
        string aux;
        aux = string(word.rbegin(),word.rend());

        for( i=0; i<tam; i++ ) {
            if( vetor[i]==1 ) {
                aux[i] = toupper(aux[i]);
            }
        }

        cout << aux;
    } else {
        string aux;
        ll metade = tam/2;
        for( i=metade; i<tam; i++ ) {
            aux += word[i];
        }
        for( i=0; i<metade; i++ ) {
            aux += word[i];
        }
        for( i=0; i<tam; i++ ) {
            if( vetor[i]==1 ) {
                aux[i] = toupper(aux[i]);
            }
        }
        cout << aux;
    }
}

int main() {
    string word, aux;
    ll i, tam;
    while( getline(cin,word) ) {
        i = 0;
        tam = word.size();

        while( i<tam  ){
            aux.clear();
            while( i<tam && ((word[i]>='a' && word[i]<='z') || (word[i]>='A' && word[i]<='Z')) ) {
                aux += word[i];
                i++;
            }
            if( aux.size() > 0 ) {
                solve( aux );
            }
            if( i<tam ) {
                cout << word[i];
                i++;
            }
        }
        cout << endl;
    }
    return 0;
} 
