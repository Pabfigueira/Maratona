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

vector<int> vetor(3);
vector<int> resp(3);

void solve() {
    if( vetor[0]!=vetor[1] && vetor[1]!=vetor[2] ) {
        resp[0] = 1; resp[1] = 1; resp[2] = 2;
        return;
    }
    
    if( vetor[0]==vetor[1] && vetor[1]==vetor[2] ) {
        if( vetor[0] == 13 ) {
            resp[0]=-1;
            return;
        } else {
            resp[0] = vetor[0]+1;
            resp[1] = resp[0];
            resp[2] = resp[0];
            return;
        }
    }

    if( vetor[0]==vetor[1] ) {
        if( vetor[2]==13 ) {
            resp[0] = 1;
            resp[1] = vetor[0]+1;
            resp[2] = resp[1];
            return;        
        } else {
            resp[0] = vetor[0];
            resp[1] = vetor[1];    
            resp[2] = vetor[2]+1;
            return;
        }
    }

    if( vetor[0]==13 ) {
        resp[0] = 1;
        resp[1] = vetor[1]+1;
        resp[2] = resp[1];
        return;
    } else {
        if( vetor[0]==12 and vetor[1]==13 ) {
            resp[0] = 1;
            resp[1] = 1;
            resp[2] = 1;
            return;
        }
        if( vetor[0] == vetor[1]-1 ) {
            resp[0] = vetor[1];
            resp[1] = vetor[2];
            resp[2] = vetor[2]+1;
            return;
        }
        resp[0] = vetor[0]+1;
        resp[1] = vetor[1];
        resp[2] = vetor[2];
        return;
    }     
}

int main() {
    while( true ) {
        cin >> vetor[0] >> vetor[1] >> vetor[2];

        if( vetor[0]+vetor[1]+vetor[2] == 0 ) break;

        sort(vetor.begin(),vetor.end());

        solve();
    
        sort(resp.begin(),resp.end());

        if( resp[0]==-1 ) cout << "*\n";
        else{
            cout << resp[0] << " " << resp[1] << " " << resp[2] << endl;
        } 
    }
    return 0;

}
