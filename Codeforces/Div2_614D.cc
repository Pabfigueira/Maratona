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

ll x_0, y_0, ax, ay, bx, by, xs, ys, t;

vector<pair<ll,ll>> nodes;
vector<vector<ll>> distances;

ll dist(pair<ll,ll> node_one, pair<ll,ll> node_two) {
  return abs(node_one.first - node_two.first) + 
        abs(node_one.second - node_two.second);
}

void IterateNode(pair<ll, ll>& node) {
  node.first = ax * node.first + bx;
  node.second = ay * node.second + by; 
}

bool ValidNode(pair<ll, ll> node) {
  if (node.first <= xs and node.second <= ys) return true; 
  if (dist(node, make_pair(xs, ys)) <= t) return true;
  return false;
}

void BuildNodes() {
  pair<ll, ll> source(xs, ys); 
  pair<ll, ll> origin(x_0, y_0);  
  pair<ll, ll> node(x_0, y_0);

  while (ValidNode(node)) {
    if (dist(source, node) <= t) {
      nodes.push_back(node);  
    }
    IterateNode(node);
  }
}

int main() {
  scanf("%lld %lld %lld %lld %lld %lld", &x_0, &y_0, &ax, &ay, &bx, &by);
  scanf("%lld %lld %lld", &xs, &ys, &t);
  BuildNodes();
  if (nodes.empty()) {
    printf("0\n");
    return 0;
  }

  distances.resize(nodes.size(), vector<ll>(nodes.size(),LINF));
  int nodes_size = nodes.size();
  for (ll i = 0; i < nodes_size; i++) {
    distances[i][i] = 0;
  }

  for (ll i = 0; i < nodes_size; i++ ) {
    for (ll j = 0; j < nodes_size; j++ ) {
      for (ll k = 0; k < nodes_size; k++) {
        distances[i][k] = min(distances[i][k], dist(nodes[i], nodes[j]) + distances[j][k]);
        distances[k][i] = distances[i][k];
      }
    }
  }

  ll ans = 0;
  for (ll i = 0; i < nodes_size; i++) {
    for (ll j = 0; j < nodes_size; j++ ) {
      if (min(dist(make_pair(xs, ys), nodes[j]), dist(make_pair(xs, ys), nodes[i])) + 
          distances[i][j] <= t) {
        ans = max(ans, j-i+1);
      }    
    }   
  }
  printf("%lld\n",ans);
  return 0;
}
