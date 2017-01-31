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

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n, a, b, c, i, c0, c1, c2, mud;
    string word;

    sc3(n,a,b);
    
    c = n-(a+b);

    cin >> word;
    
    if( word.size()!=n ) {
        cout << -1 << endl;
        return 0;
    }

    c0 = c1 = c2 = mud = 0;

    for( i=0; i<n; i++ ) {
        if( word[i] == '0' ) c0++;
        else if( word[i] == '1' ) c1++;
        else if( word[i] == '2' ) c2++; 
    }

    i=0;
    while( i<n && c0>a ) {
        if( word[i] == '0' ) {
            word[i] = '*'; 
            c0--;
            mud++;
        }
        i++;    
    }   

    i=0;
    while( i<n && c1>b ) {
        if( word[i] == '1' ) {
            word[i] = '*';
            c1--;
            mud++;
        }
        i++;
    }

    i=0;
    while( i<n && c2>c ) {
        if(word[i] == '2' ) {
            word[i] = '*';
            c2--;
            mud++;
        }
        i++;
    }

    i=0;
    while( i<n && c0<a ) {
        if( word[i] == '*' ) {
            word[i] = '0';
            c0++;
        }
        i++;
    }

    i=0;
    while( i<n && c1<b ) {
        if( word[i] == '*') {
            word[i] = '1';
            c1++;
        }
        i++;
    }

    i=0;
    while( i<n && c2<c ) {
        if( word[i] == '*' ) {
            word[i] = '2';
            c2++;
        }
        i++;
    }

    if( c1+c2+c0 == n && c0==a && c1==b && c2==c ) 
        cout << mud << endl << word << endl;
    else cout << -1 << endl;
    return 0;
}
