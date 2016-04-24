#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    
    int n;
    while(cin >> n){
        vector<int> nums, length, length2;
        while(n--){
            int tmp;
            cin >> tmp;
            nums.push_back(tmp);
            length.push_back(1);
            length2.push_back(1);
        }
        for(int i = 0; i < length.size(); i++){
            for(int j = i+1; j < length.size(); j++){
                if(nums[i] < nums[j]){
                    length[j] = max(length[j], length[i]+1);
                }
                if(nums[i] > nums[j]){
                    length2[j] = max(length2[j], length2[i]+1);
                }
            }
        }
        int n = 0, m = 0;
        int result, answer = 0;
        for(int i = 0; i < length.size(); i++){
            n = max(n, length[i]);
            m = max(m, length2[i]);
            int result;
            result = max(m, n);
            result = result*2-1;
            if(result > answer)
                answer = result;
        }
        
        cout << answer << endl;
    }
    
    return 0;
}