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

int main() {
    BUFF;

    string phrase;
    string word;
    set<string> especials;
    vector<string> line;

    int n, i, a, b, j;

    cin >> n;
    
    while( n-- ) {
        especials.clear();
        phrase.clear();
        cin >> a >> b;
        getline(cin,phrase);
        getline(cin,phrase);
            
        i=0;
        word.clear();
        while( i<=phrase.size() ) {
            if( i==phrase.size() || phrase[i]==':' || phrase[i]=='-' || phrase[i]==' ') {
                if( word.size() > 0 ) {
                    especials.insert(word);
                    word.clear();
                }
            } else {
                if( phrase[i]>='A' && phrase[i]<='Z' ) {
                    word += tolower(phrase[i]);
                } else {
                    word += phrase[i];
                }
            }
            i++; 
        }    

        for( j=0; j<b; j++ ) {
            getline(cin,phrase);
            line.clear();

            i=0;
            word.clear();
            while( i<=phrase.size() ) {
                if( i==phrase.size() || phrase[i]==':' || phrase[i]=='-' || phrase[i]==' ') {
                    if( word.size() > 0 ) {
                        line.pb(word);
                        word.clear();
                    }
                } else {
                    if( phrase[i]>='A' && phrase[i]<='Z' ) {
                        word += tolower(phrase[i]);
                    } else {
                        word += phrase[i];
                    }
                }
                i++; 
            }
            
            if( especials.find(line[0]) == especials.end() ) {
                if( line[0][0]>='a' && line[0][0]<='z' ) {
                    cout << (char)toupper(line[0][0]);
                } else {
                    cout << (char)line[0][0];
                }
            }
            for( i=1; i<line.size(); i++ ) {
                if( especials.find(line[i]) == especials.end() ) {
                    if( line[i][0]>='a' && line[i][0]<='z' ) {
                        cout << (char)toupper(line[i][0]);
                    } else {
                        cout << (char)line[i][0];
                    }        
                } else {
                    cout << (char)line[i][0];
                }
            }
            cout << endl;     
        }
        cout << endl;
    }	
	return 0;
}
