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

int n;
vector< pair<int, pair<int,int> > > vetor;

int main() {
    BUFF;
    int i, power, maximo;
        
    cin >> n;

    vetor.resize(n);

    for( i=0; i<n; i++ ) {
        cin >> vetor[i].first >> vetor[i].second.first;
        vetor[i].second.second = i+1;     
    }

    sort(vetor.begin(),vetor.end());

    vector<int> resp;
    vector<int>::iterator it;
    power = 1;
    maximo = 1;
    int who;
    i=0;
    while( i<n ) {
        if( vetor[i].second.second==n and power>=vetor[i].first ) {
            resp.pb(vetor[i].second.second);
            cout << resp.size() << endl;
            for( it=resp.begin(); it!=resp.end(); ++it ) {
                if( it!=resp.begin() ) cout << " ";
                cout << *it;
            }
            if( resp.size() > 0 ) cout << endl;
            return 0;
        }
        if( vetor[i].first<=power ) {
            if( vetor[i].second.first > maximo ) {
                maximo = vetor[i].second.first;
                who = vetor[i].second.second;
            }   
            i++;
        } else{
            if( power==maximo ) {
                cout << "No such luck\n";
                return 0;
            }
            resp.pb(who);
            power = maximo;   
        }
    }
    return 0;
}
