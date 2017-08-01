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

vector< pair<int, pair<int,int> > > vetor;
set<int> pos;
set<int>::iterator it, ita;
map<int,int> mapa;
map<int,int> mapa2;
vector<int> resp;

int main() {
    BUFF;

    int n, i;
    cin >> n;

    vetor.resize(n);
    resp.resize(n,-2);

    for( i=0; i<n; i++ ) {
        cin >> vetor[i].second.first >> vetor[i].first;
        vetor[i].second.second = i;
        mapa[vetor[i].second.first] = vetor[i].first;
        mapa2[vetor[i].second.first] = i+1;
    }

    sort(vetor.begin(),vetor.end());
    reverse(vetor.begin(),vetor.end());

    resp[vetor[0].second.second] = -1;
    pos.insert( vetor[0].second.first );

    for( i=1; i<n; i++ ) {

        it = pos.upper_bound(vetor[i].second.first);

        if( it==pos.end() ) {
            ita = it;
            ita--;
            resp[vetor[i].second.second] = mapa2[*ita];  
        } else if( it==pos.begin() ) {
            resp[vetor[i].second.second] = mapa2[*it];
        } else {
            ita = it;
            ita--;

            if( vetor[i].second.first - *ita == *it - vetor[i].second.first ) {
                if( mapa[*ita] > mapa[*it] )
                    resp[vetor[i].second.second] = mapa2[*ita];
                else
                    resp[vetor[i].second.second] = mapa2[*it];
            } else if( vetor[i].second.first - *ita > *it - vetor[i].second.first ) {
                resp[vetor[i].second.second] = mapa2[*it];      
            } else {
                resp[vetor[i].second.second] = mapa2[*ita];
            }       
        }
        pos.insert( vetor[i].second.first );
    }


    cout << resp[0];
    for( i=1; i<n; i++ ) {
        cout << " " << resp[i];
    } 
    cout << endl;
    return 0;
}
