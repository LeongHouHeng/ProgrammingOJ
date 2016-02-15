#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    
    string input, nums = "";
    cin >> input;
    for(int i = 0; i < input.length(); i++){
        if(input[i] != '+'){
            nums += input[i];
        }
    }
    sort(nums.begin(), nums.end());
    for(int i = 0; i < nums.length(); i++){
        if(i == nums.length()-1)
            cout << nums[i];
        else
            cout << nums[i] << "+";
    }
    cout << endl;
    return 0;
}