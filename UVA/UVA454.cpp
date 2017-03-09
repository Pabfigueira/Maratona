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

bool isAnagram( string word1, string word2 ) {
    string a, b;
    int i, tam;
    tam = word1.size();
    for( i=0; i<tam; i++ ) {
        if( word1[i]!=' ' ) a+=word1[i];
    }

    tam = word2.size();
    for( i=0; i<tam; i++ ) {
        if( word2[i]!=' ' ) b+=word2[i];
    }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    return a==b;
}

int main() {

    int i, n, a, tam;
    vector< string > words;
    vector< pair<string,string> > anagrams;
    string word;

    sc(n);

    getline(cin,word);
    getline(cin,word);

    for( a=0; a<n; a++ ) {
        if( a!=0 ) cout << "\n";
        words.clear();
        anagrams.clear();

        while( getline(cin,word) && word.compare("")!=0 ) {
            tam = words.size();
            for( i=0; i<tam; i++ ) {
                if( isAnagram(word,words[i]) ) {
                    if( word < words[i] ) anagrams.push_back( mp(word,words[i]) );
                    else anagrams.push_back( mp(words[i],word) );
                }
            }            
            words.push_back(word); 
        }
        sort(anagrams.begin(),anagrams.end());
        tam = anagrams.size();
        for( i=0; i<tam; i++ ) {
            cout << anagrams[i].first << " = " << anagrams[i].second << endl;
        }
    }
	
	return 0;
}
