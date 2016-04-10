#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main(){
    stringstream ss;
    int n;
    while(cin >> n){
        if(n == 0)
            break;
            
        bool check = true;
        for(int i = 1; i <= 99999; i++){
            bool b = true;
            int a = n*i;
            string strA = ""; strA += a;
            string strI = ""; strI += i;
            for(int j = 1; j < strA.length(); j++){
                for(int r = 1; r < strI.length(); r++){
                    if(strA[j] != strI[r]){
                        b = false;
                        check = false;
                    }
                }
            }
            if(b && strA.length()+strI.length() == 10){
                cout << a << "/" << i << "=" << n << endl;
            }
            
        }
        if(check){
            cout << "There are no solutions for " << n << ".";
        }
    }
    
    return 0;
}