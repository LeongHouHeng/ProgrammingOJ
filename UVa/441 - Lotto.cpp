#include <iostream>
#include <algorithm>
#include <vector>
#include <stdio.h>
using namespace std;

int main(){
    
    int n;
    int cnt = 0;
    
    while(cin >> n){
        vector<int> nums;
        if(n == 0)
            break;
            
        for(int i = 0; i < n; i++){
            int tmp;
            cin >> tmp;
            nums.push_back(tmp);
        }
        sort(nums.begin(), nums.end());
        if(cnt > 0)
            cout << endl;
        cnt++;
        for(int i = 0; i < nums.size()-5; i++){
            for(int j = i+1; j < nums.size()-4; j++){
                for(int n = j+1; n < nums.size()-3; n++){
                    for(int m = n+1; m < nums.size()-2; m++){
                        for(int l = m+1; l < nums.size()-1; l++){
                            for(int k = l+1; k < nums.size(); k++){
                                cout << nums[i] << " " << nums[j] << " " << nums[n] << " " << nums[m] << " " << nums[l] << " " << nums[k] << endl;
                                
                            }
                        }
                    }
                }
            }
        }
    }
    
    return 0;
}