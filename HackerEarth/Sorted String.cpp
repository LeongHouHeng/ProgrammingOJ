#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

string newStr(string s){
    string str(s);
    return str;
}

int main(){
    int n;
    cin >> n;
    while(n--){
        string input;
        vector<string> strs;
        cin >> input;
        char check = input[0];
        int point = 0;
        if(input.length() > 1){
            for(int i = 1; i < input.length(); i++){
                if(check != input[i]){
                    strs.push_back(newStr(input.substr(point, i)));
                }
                point = i;
                check = input[i];
            }
            
            for(int i = 0; i < strs.size(); i++){
                cout << strs[i] << endl;
            }
            
        }else{
            cout << input << endl;
        }
    }
    return 0;
}