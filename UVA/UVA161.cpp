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
#define ler freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#define imprime(x, Y)                              \
  for (int X = 0; X < Y; X++) cerr << x[X] << " "; \
  cerr << endl;
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

#define MAXTIME 5*60*60

void printa( int value ) {
    int h, m, s;

    h = value / (60*60);
    m = (value%(60*60)) / 60;
    s = (value%(60*60)) % 60;

    printf("%02d:%02d:%02d\n",h,m,s);  
}

int main() {

    int a, b, c, tam, i, init, l, r;
    vector< int > vetor;

    vector< map<int,int> > range;

    map<int,int>::iterator it, ita;

    bool valid;

    while( sc3(a,b,c) && (a||b||c) ) {
        vetor.clear();
        vetor.push_back(a);
        vetor.push_back(b);
        
        while( c ) {
            vetor.push_back(c);
            sc(c);
        }

        sort(vetor.begin(),vetor.end());

        tam = vetor.size();

        range.clear();
        range.resize(tam);

        for( i=0; i<tam; i++ ) {
            init = 0;
            while( init <= MAXTIME ) {
                if( init + vetor[i] - 5 < MAXTIME ) 
                    range[i][init] = init+vetor[i]-5;
                else
                    range[i][init] = MAXTIME;
                init += 2*vetor[i];
            } 
        }
        int cont = 0;
        it = range[0].begin();
        while( it!=range[0].end() ) {
            l = it->first;
            r = it->second;
    
            valid = true;        

            i = 1;

            while( valid && i<tam ) {
                ita = range[i].upper_bound(r);
                if( ita==range[i].begin() ) { valid=false; break; }
                ita--;
            
                if( (ita->first >= l && ita->first < r) || (ita->second>l && ita->second<=r) || 
                    (ita->first<=l && ita->second >= r) || (l<=ita->first && r >= ita->second) ) {
                    l = max(ita->first,l);
                    r = min(ita->second,r);
                    i++;
                } else {
                    valid = false;
                }                
            }
            if( valid && cont==0 ) { cont = 1; }
            else if( valid && cont==1 ) {
                printa(l);
                break;
            }
            it++;
        } 
        if( it==range[0].end() )
            printf("Signals fail to synchronise in 5 hours\n");
    }
    return 0;
}
