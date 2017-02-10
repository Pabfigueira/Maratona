#include <bits/stdc++.h>

using namespace std;

#define sc(a) scanf("%lld", &a)
#define sc2(a, b) scanf("%lld%lld", &a, &b)
#define sc3(a, b, c) scanf("%lld%lld%lld", &a, &b, &c)
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
vector< ll > resp; 
vector< pair<ll,ll> > range;
vector< vector<ll> > graph;
vector< ll > segTree;
ll l;

vector< pair<ll, pair<ll, pair<ll,ll> > > > ord;



ll query( ll p, ll i, ll j, ll e, ll d ) {
    if( i>d || j<e ) { return 0; }    
    if( e>=i && d<=j ) return segTree[p];

    ll q1 = query( 2*p, i, j, e, (e+d)/2 );
    ll q2 = query( (2*p)+1, i, j, 1+((e+d)/2), d );

    return q1+q2;
}

void update( ll p, ll value, ll position, ll e, ll d ) {
    // p = Index of the element to be updated in the original array
    // value = new value
    // position = current index in the segment tree
    // e = range start index
    // d = range end index

    if( e==d ) {
        segTree[position] = value;
        return;
    }

    ll mid = (e+d)/2;

    if( e <= p && mid>=p ) {
        update( p, value, 2*position, e, mid );
    } else {
        update( p, value, 2*position+1, mid+1, d);     
    }
    segTree[position] = segTree[2*position] + segTree[2*position+1];
}


void generateRange(ll actual, ll nivel) {
    range[actual].first = l;
    ord[actual].second.first = nivel;
    for( ll i=0; i<graph[actual].size(); i++ ) {
        l++;
        generateRange( graph[actual][i], nivel+1 ); 
    }         
    
    range[actual].second = l;
} 

int main() {

    ll n, a, b, c, i, root;
    
    sc(n);

  
    range.resize(n);
    graph.resize(n);
    segTree.resize(n*4,0);
    resp.resize(n);
    ord.resize(n);

    for( i=0; i<n; i++ ) {
        sc3(a,b,c);
        
        ord[i].first = b;
        ord[i].second.second.first = i;
        ord[i].second.second.second = c;

        if( a==-1 ) {
            root = i; 
        } else {
            graph[a-1].push_back(i);    
        }
    } 
    l = 0;
    generateRange(root,1); 

    sort( ord.begin(), ord.end() ); 

    ll eu;

    for( i=0; i<n; i++ ) {  
        eu = ord[i].second.second.first;
        resp[ eu ] = query(1,range[eu].first,range[eu].second,0,n-1);
        update(range[eu].first,ord[i].second.second.second,1,0,n-1);
    }

    for( i=0; i<n; i++ ) {
        cout << resp[i] << endl;    
    }

    return 0;
}
