#include <bits/stdc++.h> 

using namespace std;

int main() {
    
    //ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    string word;
    char letter;
    stringstream S;
    int res;
    stack<char> pilha;
    stack<int> number;

    bool byzero, error, vazio;

    while( getline(cin,word) ) {
        S.str("");
        S.clear();

        S << word; 
        
        error = false;
        byzero = false;
        vazio = false;

        while( !pilha.empty() ) {
            pilha.pop();
        }
        while( !number.empty() ) {
            number.pop();
        }

        while( !S.eof() ) {
            S >> letter;
            if( !S.fail() ) {
                pilha.push(letter);
            }
        
        }

        if( pilha.size() == 0 ) {
            error = true;
        }

        while( !vazio && !error && !pilha.empty() ) {
            while( !pilha.empty() && pilha.top() >= '0' ) {
                number.push(pilha.top() - '0');
                pilha.pop();
            }

            if( pilha.empty() ) {
                if( number.size()>1 ) {
                    error = true;
                } else {
                    break;
                }
            }

            if( !pilha.empty() && pilha.top() == '+'  && number.size()>1) {
                res = number.top();
                number.pop();
                res += number.top();
                number.pop();
                number.push(res);
                pilha.pop();
            } else if( !pilha.empty() && pilha.top() == '*'  && number.size()>1) {
                res = number.top();
                number.pop();
                res *= number.top();
                number.pop();
                number.push(res);
                pilha.pop(); 
            } else if( !pilha.empty() && pilha.top() == '-'  && number.size()>1) {
                res  = number.top();
                number.pop();
                res = number.top() - res;
                number.pop();
                number.push(res);
                pilha.pop();
            } else if( !pilha.empty() && pilha.top() == '/'  && number.size()>1) {
                res = number.top();
                number.pop();
                if( res == 0 ) {
                    byzero = true;
                    res+=1;
                }
                res = floor( number.top() / res );
                number.pop();
                number.push(res);
                pilha.pop();
            } else {
                error = true;
                break;
            }  
        }

        if( number.size() != 1 ) {
            error = true;
        }


        if( vazio ) {
        	cout << "\n";
        } else if( error ) {
            cout << "Invalid expression.\n";
        } else if( byzero ) {
            cout << "Division by zero.\n";
        } else {
            cout << "The answer is " << number.top() << ".\n";
        }
    }

    return 0;
}
