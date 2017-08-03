#include <bits/stdc++.h>

using namespace std;

#define sc(a) scanf("%d", &a)
#define sc2(a, b) scanf("%d%d", &a, &b)
#define sc3( a, b, c) scanf("%d%d%d",&a,&b,&c)
#define scs(a) scanf("%s", a)
#define pri(x) printf("%d\n", x)
#define prie(x) printf("%d ", x)
#define mp make_pair
#define pb push_back
#define BUFF ios::sync_with_stdio(false);
#define f first
#define s second

typedef long long int ll;
typedef long double ld;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vector<ii> > vvii;

const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3fll;
const ld pi = acos(-1);
const int MOD = 1e9+7;

vector< vector<int> > tree;
vector<int> father;
vector<char> perm;

set<int> solut;
set<int>::iterator it;

map<int,int> dp;

void complete( int pos ) {
    if( perm[pos] == '0' ) {
        if (pos==1 ) perm[pos] = '-';
        else perm[pos] = perm[father[pos]];
    }
    int i;
    for( i=0; i<tree[pos].size(); i++ ) {
        complete(tree[pos][i]);
    }
}

bool solve( int pos ) {

    if( dp.find(pos)!=dp.end() ) return dp[pos];
    

    if( tree[pos].size()==0 ) {
        if( perm[pos]=='+' ) {  
            if( pos==1 ) solut.insert(1);
            return dp[pos] = true;
        }
        return dp[pos] = false;
    }
    
    bool positive = true;
    
    for( int i=0; positive and i<tree[pos].size(); i++ ) {
        if( !solve(tree[pos][i]) ) positive = false;
    } 
    
    if( positive and pos==1 ) {
        solut.insert(1);
        return dp[pos] = true;
    }
    if( positive ) return dp[pos] = true;

    for( int i=0; i<tree[pos].size(); i++ ) {
        if( solve(tree[pos][i]) ) solut.insert(tree[pos][i]);
    }
    return dp[pos] = false; 
}

int main() {
    BUFF;

    int n, i, a, b;
    cin >> n;

    tree.resize(n+1);
    father.resize(n+1);
    perm.resize(n+1); 

    for( i=1; i<=n; i++ ) {
        cin >> perm[i];
    } 

    for( i=0; i<n-1; i++ ) {
        cin >> a >> b;
        tree[a].pb(b);
        father[b] = a;
    }

    complete(1);

    solve(1);

    cout << solut.size() << endl;

    for( it=solut.begin(); it!=solut.end(); ++it ) {
        if( it!=solut.begin() ) cout << " ";
        cout << *it;
    }
    if( solut.size()>0 ) cout << endl;

    return 0;
}
