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

set<pair<int,int> > broken_connections;
int n;
int matrix[3][100005] = {0};

void VerifyConnection(int down_line, int up_line) {
  if (down_line == 0 || up_line == n+1) return; 
  
  if (up_line == n) {
    if (matrix[1][down_line] + matrix[2][down_line] == 2 ||
        matrix[1][up_line] + matrix[2][down_line] == 2) {
      broken_connections.insert(make_pair(down_line, up_line));
      return;
    } 
  }
  
  if (down_line == 1) {
    if (matrix[1][up_line] + matrix[2][up_line] == 2 ||
        matrix[1][up_line] + matrix[2][down_line] == 2) {
      broken_connections.insert(make_pair(down_line, up_line));
      return;
    }
  }

  if (matrix[1][down_line] + matrix[2][down_line] == 2 ||
      matrix[1][up_line] + matrix[2][up_line] == 2 ||
      (matrix[1][down_line] + matrix[1][up_line] !=0 && 
       matrix[2][down_line] + matrix[2][up_line] !=0)) {
    broken_connections.insert(make_pair(down_line, up_line));
    return;
  } 

  // It's not broken, than update the connection
  broken_connections.erase(make_pair(down_line, up_line));
}



int main() {
  int q, i, x, y;
  sc2(n, q);
  
 
  for (i = 0; i < q; i++) {
    sc2(x, y);
    matrix[x][y] = (matrix[x][y]+1)%2;
    VerifyConnection(y, y+1);
    VerifyConnection(y-1, y);
    if (broken_connections.empty()) {
      printf("Yes\n");
    } else {
      printf("No\n");
    }
  }

  return 0;
}
