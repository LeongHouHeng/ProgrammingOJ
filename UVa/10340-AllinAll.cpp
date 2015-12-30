#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

int main(){
    string s, t;
    while(cin >> s >> t){
        int tpointer = 0;
        int spointer = 0;
        int count = 0;
        while(spointer < s.length() && tpointer < t.length()){
            if(s[spointer] == t[tpointer]){
                count++;
                spointer++;
                tpointer++;
            }else{
                tpointer++;
            }
        }
        
        if(count == s.length()){
            cout << "Yes" << endl;
        }else{
            cout << "No" << endl;
        }
    }
    
    return 0;
}