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
#define imprime(x, Y)                              \
		for (int X = 0; X < Y; X++) cerr << x[X] << " "; \
cerr << endl;
#define ler freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);

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

bool solve( string word ) {
    int i, j, raiz;
    
    raiz = sqrt(word.size());
    vector<string> vetor(4);

    for( i=0; i<raiz; i++ ) {
        vetor[0] += word[i];
    }
    
    for( i=0, j=word.size()-1; i<raiz; i++, j-- ) {
        vetor[1] += word[j];
    }   

    for( i=0, j=0; i<raiz; i++, j+=raiz ) {
        vetor[2] += word[j];
    }

    for( i=0, j=word.size()-1; i<raiz; i++, j-=raiz ) {
        vetor[3] += word[j];
    }
    
    if( vetor[0] == vetor[1] && vetor[1] == vetor[2] && vetor[2]  == vetor[3] ) 
        return true;
    return false;
}

int main() {
    
    int t, a, i, tam, raiz;
    string word, cleaned;

    sc(t);
    getline(cin,word);
    for( a=1; a<=t; a++ ) {
        printf("Case #%d:\n",a);
        getline(cin,word);
        
        tam = word.size();
        cleaned.clear();

        for( i=0; i<tam; i++ ) {
            if( word[i] >= 'a' && word[i] <= 'z' ) 
                cleaned += word[i];
        }
        tam = cleaned.size();
        raiz = sqrt(tam);
        if( raiz * raiz != tam ) {
            printf("No magic :(\n");
        } else {
            if( solve(cleaned) ) pri(raiz);
            else printf("No magic :(\n");
        }
    }
	
	return 0;
}
