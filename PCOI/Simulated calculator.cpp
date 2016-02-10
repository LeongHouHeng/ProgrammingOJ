#include <iostream>
#include <stack>
#include <string>
#include <sstream>
#include <math.h>
#include <iomanip>
using namespace std;

int main(){
    string cal = "";
    string input;
    cin >> input;
    
    stack<char> ps;
    for(int i = 0; i < input.length(); i++){
        if(input[i] >= 48 && input[i] <= 57){
            cal += input[i];
            cal += " ";
        }else if(input[i] == '@'){
            ps.push(input[i]);
        }else if((input[i] == '*') || (input[i] == '/')){
            if((!ps.empty()) && ((ps.top() != '+') && (ps.top() != '-'))){
                for(stack<char> s = ps; !s.empty(); s.pop()){
                    if((s.top() == '+') || (s.top() == '-'))
                        break;
                    cal += s.top();
                    cal += " ";
                    ps.pop();
                }
            }
            ps.push(input[i]);
            
        }else if((input[i] == '+') || (input[i] == '-')){
            if(!ps.empty()){
                for(stack<char> s = ps; !s.empty(); s.pop()){
                    ps.pop();
                    cal += s.top();
                    cal += " ";
                    if((s.top() == '+') || (s.top() == '-'))
                        break;
                        
                }
            }
            ps.push(input[i]);
        }else if(input[i] == '='){
            for(stack<char> dump = ps;  !dump.empty(); dump.pop()){
                cal += dump.top();
                cal += " ";
                ps.pop();
            }
        }
        
        
    }
    if(input.find("=") == -1){
        for(stack<char> dump = ps;  !dump.empty(); dump.pop()){
            cal += dump.top();
            cal += " ";
            ps.pop();
        }
    }
    int count = 0;    
    float op1 = 0, op2 = 0;
    string tmp;
    float tmpNum;
    stringstream ss;
    stack<float> nums, tmpNums;
    float ans = 0;
    //cout << cal << endl;
    for(int i = 0; i < cal.length(); i++){

        if(/*cal[i] == ' '*/ cal[i] >= 48 && cal[i] <= 57 && (cal[i] != ' ')){
            /*for(int j = 0; j <= i; j++){
                if((cal[j] != 'x') && (cal[j] != ' ')){
                    tmp += cal;
                }
                cal[j] = 'x';
                
            }*/
            tmp = cal[i];
            //ss << tmp;
            //ss >> tmpNum;
            tmpNum = atof(tmp.c_str());
            nums.push(tmpNum);
            //cout << "??" << tmpNum << endl;
            //if(tmpNum = )
        }else if((cal[i] == '+') || (cal[i] == '-')){
            if(cal[i] == '+'){
               op1 = nums.top();
               nums.pop();
               if(!nums.empty()){
                   op2 = nums.top();
                   nums.pop();
                   nums.push(op1+op2);
                   //cout << op1 << " " << op2 << endl;
                   //cout << "+   " << nums.top() << endl;
               }else if(nums.empty()){
                   op2 = 0;
                   nums.push(op1+op2);
               }
            }else if(cal[i] == '-'){
                op1 = nums.top();
                nums.pop();
                if(!nums.empty()){
                    op2 = nums.top();
                    nums.pop();
                    nums.push(op2 - op1);
                    //cout << "-   " << nums.top() << endl;
                }else if(nums.empty()){
                    nums.push(op1);
                }
            }
        }else if((cal[i] == '*') || (cal[i] == '/')){
            if(cal[i] == '*'){
                op1 = nums.top();
                nums.pop();
                if(!nums.empty()){
                    op2 = nums.top();
                    nums.pop();
                    nums.push(op1 * op2);
                    //cout << "*  " << nums.top() << endl;
                }else if(nums.empty()){
                    op2 = 1;
                    nums.push(op1 * op2);
                }
            }else if(cal[i] == '/'){
                op1 = nums.top();
                nums.pop();
                if(!nums.empty()){
                    op2 = nums.top();
                    nums.pop();
                    nums.push(op2 / op1);
                    //cout << op1 << " op2: " << op2 << endl;
                    //cout << nums.size() << endl;
                    //cout << "/  " << nums.top() << endl;
                    //cout << "---op1 :" << op1 << " op2: " << op2 << endl; 
                }else if(nums.empty()){
                    nums.push(op1);
                    //cout << "empty" << endl;
                }
            }
        }else if(cal[i] == '@'){
            op1 = nums.top();
            nums.pop();
            if(!nums.empty()){
                op2 = nums.top();
                nums.pop();
                nums.push(pow(op2, op1));
            }else if(nums.empty()){
                nums.push(op1);
            }
        }
        
    }
    ans = nums.top();
    cout << fixed << setprecision(3) << ans << endl;
    return 0;
}