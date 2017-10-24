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
    ll t, a, n, i, maximo;
    
    vector<ll> vetor;
    vector<ll> dp;
    vector<ll> esq;
    vector< pair<ll,ll> > resp;
    vector<ll>::iterator it;

    cin >> t;

    for( a=1; a<=t; a++ ) {
        cin >> n;
        vetor.clear();
        vetor.resize(n-1);
        dp.clear();
        dp.resize(n);
        esq.clear();
        resp.clear();

        for( i=0; i<n-1; i++ ) {
            cin >> vetor[i];     
        }     
       
        dp[0] = 0; 
        maximo = 0;
        esq.push_back(0);

        for( i=1; i<n; i++ ) {
            if( dp[i-1] + vetor[i-1] < 0 ) {
                esq.push_back(i);
            } 
            dp[i] = max(0ll,vetor[i-1]+dp[i-1]);
            maximo = max(maximo,dp[i]);             
        }
        
        if( maximo == 0 ) cout << "Route " << a << " has no nice parts\n";
        else {
            i=1;
            while( i<n ) {
                if( dp[i]==maximo ) {
                    it = upper_bound(esq.begin(),esq.end(),i);
                    it--;
                    resp.push_back( mp(i-(*it),-(*it)) );
                }                 
                i++; 
            } 
            sort(resp.begin(),resp.end());
            cout << "The nicest part of route " << a << " is between stops " << 1-(resp[resp.size()-1].second) << " and " << 1+ resp[resp.size()-1].first - resp[resp.size()-1].second << endl;     
        } 
    }
    return 0;
}
