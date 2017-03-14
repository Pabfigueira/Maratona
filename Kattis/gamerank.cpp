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
#define imprime(x, Y)                                \
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

int tam;
string word;

int solve( int pos, int level, int stars, int consecutives ) {
    if( level==0 ) return 0;
    if( pos==tam ) return level;

    //cout << pos << " " << level << " " << stars << " " << consecutives << endl;

    if( word[pos] == 'W' ) {
        consecutives++;
        if( level>=6 ) {
            if( consecutives>=3 ) {    
                if( level<=25 && level>=21 && stars==1 ) return solve(pos+1,level-1,1,consecutives);
                if( level<=20 && level>=16 && stars==2 ) return solve(pos+1,level-1,1,consecutives);
                if( level<=15 && level>=11 && stars==3 ) return solve(pos+1,level-1,1,consecutives);
                if( level<=10 && level>=6  && stars==4 ) return solve(pos+1,level-1,1,consecutives);
                
                if( level<=25 && level>=21 && stars==2 ) return solve(pos+1,level-1,2,consecutives);
                if( level<=20 && level>=16 && stars==3 ) return solve(pos+1,level-1,2,consecutives);
                if( level<=15 && level>=11 && stars==4 ) return solve(pos+1,level-1,2,consecutives);
                if( level<=10 && level>=6  && stars==5 ) return solve(pos+1,level-1,2,consecutives);
                
                return solve(pos+1,level,stars+2,consecutives);
            } else {
                if( level<=25 && level>=21 && stars==2 ) return solve(pos+1,level-1,1,consecutives);
                if( level<=20 && level>=16 && stars==3 ) return solve(pos+1,level-1,1,consecutives);
                if( level<=15 && level>=11 && stars==4 ) return solve(pos+1,level-1,1,consecutives);
                if( level<=10 && level>=6  && stars==5 ) return solve(pos+1,level-1,1,consecutives);
                return solve(pos+1,level,stars+1,consecutives);
            }     
        } else {
            if( stars==5 ) return solve(pos+1,level-1,1,consecutives);
            else return solve(pos+1,level,stars+1,consecutives);
        }
    } else {
        if( (level>=1 && level<20) || (level==20 && stars>0) ) {
            if( stars>0 ) {
                stars--;
                return solve(pos+1,level,stars,0);
            } else {
                if( level>=15 && level<=19 ) {
                    stars = 2;
                } else if( level>=10 && level<=14 ) {
                    stars = 3;
                } else {
                    stars = 4;
                }
                return solve(pos+1,level+1,stars,0);
            }
        } else {
            return solve(pos+1,level,stars,0);
        }
    }    
}


int main() {
        
    cin >> word;
    tam = word.size();

    int resp = solve(0,25,0,0);
    
    if( !resp ) printf("Legend\n");
    else pri(resp);
  
    return 0;
}