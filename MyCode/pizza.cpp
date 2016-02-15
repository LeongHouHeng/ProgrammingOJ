#include <iostream>
#include <string>
using namespace std;

int main(){
    int n;
    while(cin >> n){
        string str;
        while(n--){
            cin >> str;
            cout << str;
            if(n > 0){
                cout << "_";
            }
        }
        
    }
    return 0;
}