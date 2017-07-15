#include <bits/stdc++.h>

using namespace std;

#define sc(a) scanf("%d", &a)
#define sc2(a,b) scanf("%d %d", &a, &b)
#define sc3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define scs(a) scanf("%s", a)
#define pri(x) printf("%d\n",x)
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

string find(string resp, vector<int>& used, int qt) {
    int valor, tam;
    bool deu = false;
    while( !deu ) {
        tam = resp.size();
        valor = (resp[tam-1]-'0')-1;
        while( valor!=-1 && used[valor]>=2 ) {
            valor--;
        }
        if( valor!=-1 ) {
            used[resp[tam-1]-'0']--;
            resp.erase(resp.begin()+(tam-1));
            resp += char(valor + '0');
            used[valor]++;
            deu = true;
        } else {
            used[resp[tam-1]-'0']--;
            resp.erase(resp.begin()+(tam-1));
            qt++;
        }
    }
    int j = 9;
    while( qt-- ) {
        while( used[j]==2 ) j--;
        resp += char(j+'0');
        used[j]++;
    }
    while( resp.size() && resp[0]=='0' ) resp.erase(resp.begin());
    return resp;
}

int main() { 
    int t, i;
    string number, resp;
    
    vector<int> used;
    bool fim;
    cin >> t;
    getline(cin,resp);
    while(t--) {
        used.clear();
        used.resize(10,0);
        number.clear();
        resp.clear();

        getline(cin,number);
    
        while( number.size() && number[0]=='0' ) number.erase(number.begin());

        if( number.size() > 20 ) cout << "99887766554433221100\n";

        else {
            fim = false;
            for( i=0; i<number.size() && !fim; i++ ) {
                if( used[number[i]-'0']<2 ) {
                    resp += number[i]; 
                    used[number[i]-'0']++;
                } else {
                    resp += number[i];
                    used[number[i]-'0']++;
                    string nresp = find(resp,used,number.size()-(i+1));
                    cout << nresp << endl;
                    fim = true;
                }
            }
            if( !fim ) cout << resp << endl;
        }
    }
    return 0;
}
