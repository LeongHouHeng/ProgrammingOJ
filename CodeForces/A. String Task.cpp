#include <iostream>
#include <string>
using namespace std;
void toLower(string &str){
    for(int i = 0; i < str.length(); i++){
        if(str[i] >= 'A' && str[i] <= 'Z'){
            str[i] = str[i] - ('Z'-'z');
        }
    }
}

int main(){
    string input;
    while(cin >> input){
        string ans = ".";
        string tmp ="";
        toLower(input);
        for(int i = 0; i < input.length(); i++){
            if((input[i] != 'a') && (input[i] != 'e') && (input[i] != 'i') && (input[i] != 'o') && 
                (input[i] != 'u') && (input[i] != 'y')
            ){
                tmp += input[i];
            }
        }
        for(int i = 0; i < tmp.length(); i++){
            if(i > 0)
                ans += '.';
            
            ans += tmp[i];
        }
        cout << ans << endl;
    }
    return 0;
}