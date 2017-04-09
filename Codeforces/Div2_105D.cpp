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

map< pair<double, pair<double,double> >, double > visited;


double calc( double w, double b, double who ) {
    if( visited.find( mp( w, mp(b,who) ) ) != visited.end() ) 
        return visited[ mp(w,mp(b,who) ) ];
    if( who==0 ) {
        if( w==0 ) return 0;
        if( b==0 ) return 1;
        return visited[ mp(w,mp(b,who) ) ] = (w/(b+w)) + ( (b/(b+w)) * calc(w,b-1,1) );
    } else if( who==1 ) {
        if( w==0 ) return 1;
        if( b==0 ) return 0;
        return visited[ mp(w,mp(b,who) ) ] = b/(b+w) * calc(w,b-1,2);
    } else {
        if( w==0 ) return 0;
        if( b==0 ) return 1;

        return visited[ mp(w,mp(b,who) ) ] = ( b/(b+w) * calc(w,b-1,0) ) + ( w/(b+w) * calc(w-1,b,0) );
    }
}


int main() {
    
    double w, b;

    scanf("%lf %lf",&w,&b);

    printf("%.9lf\n",calc(w,b,0));

    return 0;
}
