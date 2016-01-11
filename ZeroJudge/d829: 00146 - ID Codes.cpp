#include <iostream>
#include <string>
#include <algorithm>
#include <stdio.h>
using namespace std;

void swap(char &a, char &b){
    char tmp = a;
    a = b;
    b = tmp;
}

int main(){
    string input;
    while(cin >> input){
        if(input[0] == '#')
            break;
        
        if(next_permutation(input.begin(), input.end())){
            for(int i = 0; i < input.length(); i++){
                printf("%c", input[i]);
            }
            cout << endl;
        }else{
            cout << "No Successor" << endl;
        }
    }
    
    return 0;
}