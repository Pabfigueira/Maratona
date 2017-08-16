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
    string card;
    
    int pts, extra, stops, i;

    set<char> setS;
    set<char> setH;
    set<char> setD;
    set<char> setC;
    
    while( cin >> card ) {
        pts = 0;
        extra = 0;
        stops = 0;

        setS.clear();
        setH.clear();
        setD.clear();
        setC.clear();

        if( card[0]=='A' ) pts+=4;
        if( card[0]=='K' ) pts+=3;
        if( card[0]=='Q' ) pts+=2;
        if( card[0]=='J' ) pts+=1;

        if( card[1]=='S' ) {
            setS.insert(card[0]);
        } else if( card[1]=='H' ) {
            setH.insert(card[0]);
        } else if( card[1]=='D' ) {
            setD.insert(card[0]);
        } else {
            setC.insert(card[0]);
        }

        for( i=0; i<12; i++ ) {
            cin >> card;
            
            if( card[0]=='A' ) pts+=4;
            if( card[0]=='K' ) pts+=3;
            if( card[0]=='Q' ) pts+=2;
            if( card[0]=='J' ) pts+=1;


            if( card[1]=='S' ) {
                setS.insert(card[0]);
            } else if( card[1]=='H' ) {
                setH.insert(card[0]);
            } else if( card[1]=='D' ) {
                setD.insert(card[0]);
            } else {
                setC.insert(card[0]);
            }
        }
    

        if( setS.find('K')!=setS.end() and setS.size()==1 ) pts--;
        if( setH.find('K')!=setH.end() and setH.size()==1 ) pts--;
        if( setD.find('K')!=setD.end() and setD.size()==1 ) pts--;
        if( setC.find('K')!=setC.end() and setC.size()==1 ) pts--;
        
        if( setS.find('Q')!=setS.end() and setS.size()<=2 ) pts--;
        if( setH.find('Q')!=setH.end() and setH.size()<=2 ) pts--;
        if( setD.find('Q')!=setD.end() and setD.size()<=2 ) pts--;
        if( setC.find('Q')!=setC.end() and setC.size()<=2 ) pts--;

        if( setS.find('J')!=setS.end() and setS.size()<=3 ) pts--;
        if( setH.find('J')!=setH.end() and setH.size()<=3 ) pts--;
        if( setD.find('J')!=setD.end() and setD.size()<=3 ) pts--;
        if( setC.find('J')!=setC.end() and setC.size()<=3 ) pts--;

        if( setS.size()==2 ) extra++;
        if( setH.size()==2 ) extra++;
        if( setD.size()==2 ) extra++;
        if( setC.size()==2 ) extra++;
    
        if( setS.size()==1 ) extra+=2;
        if( setH.size()==1 ) extra+=2;
        if( setD.size()==1 ) extra+=2;
        if( setC.size()==1 ) extra+=2;
    
        if( setS.size()==0 ) extra+=2;
        if( setH.size()==0 ) extra+=2;
        if( setD.size()==0 ) extra+=2;
        if( setC.size()==0 ) extra+=2;
    
        if( setS.find('A')!=setS.end() or (setS.find('K')!=setS.end() and setS.size()>=2) or 
           (setS.find('Q')!=setS.end() and setS.size()>=3) ) stops++;

        if( setH.find('A')!=setH.end() or (setH.find('K')!=setH.end() and setH.size()>=2) or 
           (setH.find('Q')!=setH.end() and setH.size()>=3) ) stops++;

        if( setD.find('A')!=setD.end() or (setD.find('K')!=setD.end() and setD.size()>=2) or 
           (setD.find('Q')!=setD.end() and setD.size()>=3) ) stops++;

        if( setC.find('A')!=setC.end() or (setC.find('K')!=setC.end() and setC.size()>=2) or 
           (setC.find('Q')!=setC.end() and setC.size()>=3) ) stops++;
        
        if( pts>=16 and stops==4 ) cout << "BID NO-TRUMP\n";
        else if( pts+extra>=14 ) {
            cout << "BID ";
            if( setS.size()>=setH.size() and setS.size()>=setD.size() and setS.size()>=setC.size() ) cout << "S";
            else if( setH.size()>=setS.size() and setH.size()>=setD.size() and setH.size()>=setC.size() ) cout << "H";
            else if( setD.size()>=setS.size() and setD.size()>=setH.size() and setD.size()>=setC.size() ) cout << "D";
            else cout << "C"; 
            cout << endl;
        } 
        else cout << "PASS\n";
    }
	
	return 0;
}
