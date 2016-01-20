#include <iostream>
#include <string>

using namespace std;

int main(){
    string input;
    while(cin >> input){
        for(int i = 0; i < input.size(); i++){
            input[i]= input[i] - 7;
            cout << input[i];
        }
        cout << endl;
        
    }
    
    return 0;
}