#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

int main(){
    int n;
    
    scanf("%d", &n);
    char cip;
    while(n--){
        string input;
        int ic = 0;
        
        //char c = cin.get();
        getline(cin, input);
        /*if(input[0]==' ' || input.empty()){
            ic = 0;
        }else{*/
            for(int i = 0; i < input.length(); i++){
               
                if(input[i] == '('){
                    if(ic < 0)
                        break;
                    ic += 1;   
                    
                }
                if(input[i] == '['){
                    if(ic < 0)
                        break; 
                    ic += 10;
                                       
                }
                if(input[i] == ')')
                    ic -= 1;
                if(input[i] == ']')
                    ic -= 10;
                    
            }
        //}
        
        if(ic == 0){
            cout << "Yes" << endl;
        }else{
            cout << "No" << endl;
            ic = 0;
        }
        
    }
    
    return 0;
}