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
  int n, a, b, i;

  cin >> n; 

  set<int> resp;
  set<int>::iterator it;

  vector< vector<int> > vetor(n,vector<int>(3));

  a = 0;
  b = 0;

  for( i=0; i<n; i++ ) {
    cin >> vetor[i][0] >> vetor[i][1] >> vetor[i][2];
    sort(vetor[i].begin(),vetor[i].end());
    a = max(a,vetor[i][0]);
    b = max(b,vetor[i][1]);
  }	

  for( i=0; i<n; i++ ) {
    if( vetor[i][1] >= a and vetor[i][2] >= b ) resp.insert(i+1);
  }
  cout << resp.size() << endl;
  for( it=resp.begin(); it!=resp.end(); ++it ) {
    if( it!=resp.begin() ) cout << " ";
    cout << *it;
  }
  cout << endl;
	return 0;
}
