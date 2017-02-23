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

int main() {
    int  valueA, i, valueB, ganho, maximo;

    vector<int> a;
    set<int> b;
    set<int>::iterator it;

    set<int> used;

    while( true ) {
        ganho = 0;
        maximo = 0;
        used.clear();
        a.clear();
        a.resize(3);
        b.clear();

        sc3(a[0],a[1],a[2]);
        sc2(valueA,valueB);
        if( a[0] + a[1] + a[2] + valueA + valueB == 0 ) break;
        
        b.insert(valueA);
        b.insert(valueB);
    
        used.insert(a[0]); used.insert(a[1]); used.insert(a[2]);
        used.insert(valueA); used.insert(valueB);

        sort(a.begin(),a.end());
    
        for( i=0; i<3; i++ ) {
            if( b.size()>0 && a[i]>*(b.begin()) ) {
                b.erase(b.begin());
                ganho++;
            } else {
                maximo = a[i];
            }                 
        }
        
        if( ganho == 2 ) pri(-1);
        else if( ganho == 0 ) {
            i = 1;
            while( used.find(i)!=used.end() ) i++;
            pri(i); 
        } else if( ganho == 1 ) {
            i = maximo+1;
            while( used.find(i)!=used.end() ) i++;
            if( i == 53 ) pri(-1);
            else pri(i); 
        }  
    }    

    return 0;
}
