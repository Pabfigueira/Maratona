#include <bits/stdc++.h>

using namespace std;

#define sc(a) scanf("%d", &a)
#define sc2(a, b) scanf("%d%d", &a,&b)
#define sc3(a, b, c) scanf("%d%d%d",&a, &b,&c)
#define scs( a ) scanf("%s", a)
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

int main() {

    int n, i, j, h;
    cin >> n;
    vector<int> vetor(2*n);
    vector<int> resp(2*n);

    for( i=0; i<2*n; i++ ) {
        cin >> vetor[i];
    }
    sort(vetor.begin(),vetor.end());

    j = (2*n)-1;
    h = 0;
    for( i=0; i<2*n; i++ ) {
        if( i%2==0 ) {
            resp[i] = vetor[h];
            h++;
        } else {
            resp[i] = vetor[j];
            j--;
        }                    
    }

    for( i=0; i<2*n; i++ ){ 
        if( i>0 ) cout << " ";
        cout << resp[i];
    }
    cout << endl;
    return 0;
}
