#include <iostream>
#include <stack>
#include <string>
using namespace std;

/*
@
* /
+ -

*/

int main(){
    
    string input;
    cin >> input;
    stack<char> ps;
    int count = 0;
    for(int i = 0; i < input.length(); i++){
        if(input[i] >= 48 && input[i] <= 57){
            cout << input[i];
        }else if(input[i] == '@'){
            ps.push(input[i]);
        }else if((input[i] == '*') || (input[i] == '/')){
            if((!ps.empty()) && ((ps.top() != '+') && (ps.top() != '-'))){
                for(stack<char> s = ps; !s.empty(); s.pop()){
                    if((s.top() == '+') || (s.top() == '-'))
                        break;
                        
                        
                    cout << s.top();
                    ps.pop();
                }
            }
            ps.push(input[i]);
            
        }else if((input[i] == '+') || (input[i] == '-')){
            if(!ps.empty()){
                for(stack<char> s = ps; !s.empty(); s.pop()){
                    cout << s.top();
                    ps.pop();
                    if((s.top() == '+') || (s.top() == '-'))
                        break;
                        
                }
            }
            ps.push(input[i]);
        }else if(input[i] == '='){
            for(stack<char> dump = ps;  !dump.empty(); dump.pop()){
                cout << dump.top();
                ps.pop();
            }
        }
        
        
    }
    if(input.find("=") == -1){
        for(stack<char> dump = ps;  !dump.empty(); dump.pop()){
            cout << dump.top();
            ps.pop();
        }
    }
    cout << endl;
    return 0;
}