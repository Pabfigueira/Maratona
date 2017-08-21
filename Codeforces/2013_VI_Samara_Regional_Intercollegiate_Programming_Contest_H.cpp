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

int dista( pair<int,int> one, pair<int,int> two ) {
    return (one.first-two.first)*(one.first-two.first) + (one.second-two.second)*(one.second-two.second); 
}

unsigned int bgcd( unsigned int a, unsigned int b ) {
    unsigned int temp;
    int shift;

    if( a==0 ) return b;
    if( b==0 ) return a;

    for( shift=0; ((a|b)&1)==0; shift++ ) {
        a>>=1; b>>=1;
    }
    while((a&1)==0) a>>=1;
    
    while( b!=0 ) {
        while((b&1)==0) b>>=1;
        if(a>b) {
            temp=b; b=a; a=temp;
        }
        b-=a;    
    }
    return a<<shift;
}


int main() {
    
    vector< pair<int,int> > star1(3);
    vector< pair<int,int> > star2(3);

    vector< int > one(3);
    vector< int > two(3);

    int i, gc;

    for( i=0; i<3; i++ ) {
        cin >> star1[i].first >> star1[i].second;
    }

    for( i=0; i<3; i++ ) {
        cin >> star2[i].first >> star2[i].second;
    }

    one[0] = dista(star1[0],star1[1]);
    one[1] = dista(star1[0],star1[2]);
    one[2] = dista(star1[1],star1[2]); 

    two[0] = dista(star2[0],star2[1]);
    two[1] = dista(star2[0],star2[2]);
    two[2] = dista(star2[1],star2[2]);

    gc = bgcd(one[0],bgcd(one[1],one[2]));
    for( i=0; i<3; i++ ) {
        one[i] /= gc;
    }

    gc = bgcd(two[0],bgcd(two[1],two[2]));
    for( i=0; i<3; i++ ) {
        two[i] /= gc;
    }

    sort(one.begin(),one.end());
    sort(two.begin(),two.end());

    if( one==two ) cout << "YES\n";
    else cout << "NO\n";

    return 0;
}
