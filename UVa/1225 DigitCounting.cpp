#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int zero, one, two, three, four, five, six, seven, eight, nine;
void addNum(int num){
    switch(num){
        case 0:
            zero++;
            break;
        case 1:
            one++;
            break;
        case 2:
            two++;
            break;
        case 3:
            three++;
            break;
        case 4:
            four++;
            break;
        case 5:
            five++;
            break;
        case 6:
            six++;
            break;
        case 7:
            seven++;
            break;
        case 8:
            eight++;
            break;
        case 9:
            nine++;
            break;
    }
}

int main(){
    int t;
    while(cin >> t){
        while(t--){
            zero = 0;one = 0; two = 0; three = 0; four = 0; five = 0; six = 0; seven = 0; eight = 0; nine = 0;
            int n;
            vector<int> vn;
            cin >> n;
            for(int i = 1; i <= n; i++){
                vn.push_back(i);
            }
            

            for(int i = 0; i < vn.size(); i++){
                string str;                
                stringstream ss;
                ss << vn[i];
                ss >> str;
                for(int j = 0; j < str.length(); j++){
                    int ia = str[j] - '0';
                    addNum(ia);
                }
            
            }
            
            cout << zero << " " << one << " " << two << " " << three << " " << four << " " << five << " " << six << " " << seven << " " << eight << " " << nine << endl;
            
        }
    }
    
    return 0;
}