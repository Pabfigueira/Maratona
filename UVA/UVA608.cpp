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

    int n, a, b, tam, i;
    
    string w1, w2, op;
    
    map<char,int> m1;
    map<char,int> m2;
    map<char,int> m3;
    map<char,int>::iterator it;

    map<int, pair<char,int> > resp;
    map<int, pair<char,int> >::iterator ita;

    sc(n);
    
    for( a=0; a<n; a++ ) {
        m1.clear();
        m2.clear();
        m3.clear();
        resp.clear();

        for( b=0; b<3; b++ ) {
            cin >> w1 >> w2 >> op; 
            tam = w1.size();
            for( i=0; i<tam; i++ ) {
                if( op.compare("even") == 0 ) {
                    m1[w1[i]]++;
                    m1[w2[i]]++;
                    
                    m2.erase(w1[i]);
                    m2.erase(w2[i]);
                    m3.erase(w1[i]);
                    m3.erase(w2[i]);
                } else if( op.compare("up") == 0 ) {
                    if( m1.find(w1[i])==m1.end() ) m3[w1[i]]++;    
                    if( m1.find(w2[i])==m1.end() ) m2[w2[i]]++;
                } else {
                    if( m1.find(w1[i])==m1.end() ) m2[w1[i]]++;    
                    if( m1.find(w2[i])==m1.end() ) m3[w2[i]]++;
                } 
            }
        }

        for( it = m2.begin(); it!=m2.end(); ++it ) {
            resp[it->second] = mp(it->first,2);
        }
        for( it = m3.begin(); it!=m3.end(); ++it ) {
            resp[it->second] = mp(it->first,3);
        }

        ita = resp.end();
        ita--;

        if( ita->second.second == 2 ) printf("%c is the counterfeit coin and it is light.\n", ita->second.first );
        else printf("%c is the counterfeit coin and it is heavy.\n", ita->second.first );
    }
    return 0;
}
