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

int n, column;
string numbers;

vector< vector<char> > matriz;

void toBraile() {
    string one, two, three;
    int i;

    for( i=0; i<n; i++ ) {
        if( i!=0 ) {
            one+=' ';
            two+=' ';
            three+=' ';
        }
        //one
        if( numbers[i]=='1' || numbers[i]=='2' || numbers[i]=='5' || numbers[i]=='8' ) {
            one += "*.";
        } else if( numbers[i]=='3' || numbers[i]=='4' || numbers[i]=='6' || numbers[i]=='7' ) {
            one += "**";
        } else {
            one += ".*";
        }

        //two
        if( numbers[i]=='1' || numbers[i]=='3' ) {
            two += "..";
        } else if( numbers[i]=='2' || numbers[i]=='6' || numbers[i]=='9' ) {
            two += "*.";
        } else if( numbers[i]=='4'|| numbers[i]=='5' ) {
            two += ".*";
        } else {
            two += "**";
        }
        
        three += "..";
            
    }
    cout << one << endl;
    cout << two << endl;
    cout << three << endl;
}

void toNumber() {
    string resp;
    int j;

    for( j=0; j<2*n; j+=2 ) {
        if( matriz[0][j] == '*' ) {
            if( matriz[0][j+1] == '*' ) {
                if( matriz[1][j]=='*' and matriz[1][j+1]=='*' ) resp+='7';
                else if( matriz[1][j]=='*' ) resp += '6';
                else if( matriz[1][j+1]=='*' ) resp+='4';
                else resp+='3';
            } else {
                if( matriz[1][j]=='*' and matriz[1][j+1]=='*' ) resp+='8';
                else if( matriz[1][j]=='*' ) resp+='2';
                else if( matriz[1][j+1]=='*') resp += '5';
                else resp+='1';
            } 
        } else {
            if( matriz[1][j+1] == '*' ) resp += '0';
            else resp += '9';
        }   
    } 
    cout << resp << endl;
}

int main() {
    char option;
    int i, j;

    while( cin >> n && n ) { 
        cin >> option;  
        if( option=='S' ) {
            cin >> numbers;
            toBraile();                 
        } else {
            column = (2*n);
            matriz.clear();
            matriz.resize(3, vector<char>(column));
            for( i=0; i<3; i++ ) {
                for( j=0; j<n*2; j++ ) {
                    cin >> matriz[i][j];
                }
            }
            toNumber();                
        }
    }
    return 0;
}
