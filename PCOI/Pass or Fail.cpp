#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool count(vector<int> nums, int source){
    int num = 0;
    nums.push_back(source);
    std::sort(nums.begin(), nums.end(), greater_equal<int>());
    
    for(int i = 0; i < nums.size()-2; i++){
        num += nums[i];
    }
    if((num / (nums.size()-2)) >= 50){
        return true;
    }else{
        return false;
    }
    
}

int main(){
    
    int N;
    vector<int> vn;
    cin >> N;
    N = N-1;
    while(N--){
        int source;
        cin >> source;
        vn.push_back(source);
    }
    
    for(int i = 0; i <= 100; i++){
        if(i == 100 && count(vn, i) == false){
            cout << "FAIL" << endl;
            break;
        }
        if(count(vn, i) == true){
            cout << i << endl;
            break;
        }
        
    }
    
    return 0;
}