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

set<int> closed_restaurants;
int n, s, k;

int FindRestaurant() {
  if (closed_restaurants.find(s) == closed_restaurants.end()) {
    return 0;
  }
  int go_down, go_up, stairs;
  go_down = s-1; go_up = s+1;
  stairs = 1;
  while (stairs <= n) {
    if (go_down >= 1) {
      if (closed_restaurants.find(go_down) == closed_restaurants.end()) {
        return stairs;
      }
      go_down--;
    }
    if (go_up <= n) {
      if (closed_restaurants.find(go_up) == closed_restaurants.end()) {
        return stairs;
      }
      go_up++;
    }
    stairs++;
  }
  return stairs;
}

int main() {  
  int t, i, floor;
  sc(t);
  while (t--) {
    closed_restaurants.clear();
    sc3(n, s, k);
    for (i = 0; i < k; i++) {
      sc(floor);
      closed_restaurants.insert(floor);
    }
    pri(FindRestaurant());
  } 
  return 0;
}
