#include <iostream>
#include <string>
using namespace std;

string s = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;\'ZXCVBNM,./";
int main(){

    char c;
    while((c = getchar()) != '\n'){
        for(int i = 0; i < s.length(); i++){
            if(c == s[i]){
              putchar(s[i-1]);
            }
        }
    }
    cout << endl;
    return 0;
}