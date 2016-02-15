#include <iostream>
#include <string>
using namespace std;

void toLower(string &str){
    for(int i = 0; i < str.length(); i++){
        if(str[i] >= 'A' && str[i] <= 'Z'){
            str[i] = str[i] - ('Z' - 'z');
        }
    }
}

int main(){
    string input, input2;
    cin >> input;
    cin >> input2;
    toLower(input);
    toLower(input2);
    
    if(input.compare(input2) > 0){
        cout << 1 << endl;
    }else if(input.compare(input2) < 0){
        cout << -1 << endl;
    }else{
        cout << 0 << endl;
    }
    
    return 0;
}