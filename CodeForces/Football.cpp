#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main(){
    string input;
    while(cin >> input){
        int count = 0;
        char last = '/';
        for(int i = 0; i < input.length(); i++){
            if(last == '/'){
                last = input[i];
                count++;
                continue;
            } 
            if(input[i] == last){
                count++;
                if(count >= 7){
                    cout << "YES" << endl;
                    break;
                }
            }else if(input[i] != last){
                count = 0;
                last = input[i];
                count++;
            }
        }
        if(count < 7){
            cout << "NO" << endl;
        }
    }
    return 0;
}
