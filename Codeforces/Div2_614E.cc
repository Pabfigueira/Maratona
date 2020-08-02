#include <bits/stdc++.h>

using namespace std;

#define sc(a) scanf("%lld", &a)
#define sc2(a, b) scanf("%lld%lld", &a, &b)
#define sc3(a, b, c) scanf("%d%d%d", &a, &b, &c)
#define scs(a) scanf("%s", a)
#define pri(x) printf("%lld\n", x)
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

ll n;
vector<set<ll>> graph;
vector<vector<ll>> par;
vector<vector<ll>> sub;
vector<vector<ll>> dp;

void PreComputeParAndSub(ll root, ll parent, ll node) {
  // par(r,u) : the parent of vertex u if we root the tree at vertex r.
  // sub(r,u): the number of vertices in the subtree of vertex u if we root the tree at vertex r.
  sub[root][node] = 1;
  for (auto it : graph[node]) {
    if (it != parent) {
      par[root][it] = node;
      PreComputeParAndSub(root, node, it);
      sub[root][node] += sub[root][it];   
    }
  }
}

ll GetDP(ll node_one, ll node_two) {
  if (node_one == node_two) return 0;
  if (dp[node_one][node_two] != -1) {
    return dp[node_one][node_two];
  }
  
  dp[node_one][node_two] =  sub[node_one][node_two] * sub[node_two][node_one] + 
      max(GetDP(par[node_two][node_one], node_two), GetDP(node_one, par[node_one][node_two]));   
  return dp[node_one][node_two];
}

int main() {
  ll i, j, a, b;

  sc(n);
  graph.resize(n);
  par.resize(n, vector<ll>(n, -1ll));
  sub.resize(n, vector<ll>(n, 0ll));
  dp.resize(n, vector<ll>(n, -1));

  for (i = 0; i < n-1; i++) {
    sc2(a, b);
    a--; b--;
    graph[a].insert(b);
    graph[b].insert(a);
  }
 
  for (i = 0; i < n; i++) {
    PreComputeParAndSub(i, -1, i);
  } 

  ll ans = 0;
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      ans = max(ans, GetDP(i,j));
    }
  }
  pri(ans);
  return 0;
}
