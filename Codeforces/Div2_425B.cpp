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
vector<int> permite;
string word, pattern;
ll pos;

bool ok() {
    ll i, j;

    if( pos==string::npos ) {
        if( pattern.size()!=word.size() ) return false;
        for( i=0; i<word.size(); i++ ) {
            if( word[i]=='?' ) {
                if( permite[pattern[i]-'a']==0 ) return false;
            } else {
                if( word[i]!=pattern[i] ) return false;
            }
        }
        return true;
    } else {
        ll tamERR = pattern.size() - (word.size()-1);
        
        for( i=0, j=0; i<pos; i++,j++) {
            if( word[i]=='?' ) {
                if( permite[pattern[j]-'a']==0 ) return false;
            } else {
                if( word[i]!=pattern[j] ) return false;
            }
        }  
        i++;
        ll limite = j+tamERR;
        for(;j<limite; j++ ) {
            if( permite[pattern[j]-'a']==1 ) return false;
        }
        
        for(;i<word.size();i++,j++) {
            if( word[i]=='?' ) {
                if( permite[pattern[j]-'a']==0 ) return false;
            } else {
                if( word[i]!=pattern[j] ) return false;
            }
        }         
        return true;
    }
}

int main() {
    BUFF;
    ll i, n;
    vector<char>::iterator it;
    permite.resize(30,0);
    
    getline(cin,word);

    for( i=0; i<word.size(); i++ ) {
        permite[word[i]-'a'] = 1;
    }
    getline(cin,word);

    pos = word.find('*');

    cin >> n;
    getline(cin,pattern);
    for( i=0; i<n; i++ ) {
        getline(cin,pattern);
        if( ok() ) cout << "YES\n";
        else cout << "NO\n";    
    }
    return 0;
}
