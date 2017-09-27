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

vector<int> p;

int Find(int a) { return p[a]==a ? a : p[a] = Find(p[a]); }

void Union(int a, int b) { p[Find(a)] = Find(b); }

int main() {
	int n, m, soma, i;

    soma = 0;

    scanf("%d%d",&n,&m);

    p.resize(n);

    vector< pair<int,pair<int,int> > > edges(m);

    for( i=0; i<n; i++ ) {
        p[i] = i;
    }

    for( i=0; i<m; i++ ) {
        scanf("%d%d%d",&edges[i].second.first,&edges[i].second.second,&edges[i].first);
        edges[i].second.first--;
        edges[i].second.second--;
    }

    sort(edges.begin(),edges.end());

    for( i=0; i<m; i++ ) {
        if( Find(edges[i].second.first)!=Find(edges[i].second.second) ) {
            soma+=edges[i].first;
            Union(edges[i].second.first,edges[i].second.second);
        }
    }   
    printf("%d\n",soma);
	return 0;
}
