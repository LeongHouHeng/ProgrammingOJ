#include <iostream>
#include <string>
#include <stdio.h>
using namespace std; 

int main(){
    int t;
    while(cin >> t){
        while(t--){
            string input;
            cin >> input;
            int countChara = 0; //O出現次數
            int result = 0;
            for(int i = 0; i < input.length(); i++){
                    
                if(input[i] == 'O'){
                    countChara++;
                    result += countChara;
                }else if(input[i] == 'X'){
                    countChara = 0;
                }
            }
            cout << result << endl;
            
        }
    }
    
}