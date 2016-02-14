#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n, m, count = 0;
    while(cin >> n){
        if(n == 0)
            break;
        vector<int>num;
        while(n--){
            int tmp;
            cin >> tmp;
            num.push_back(tmp);
        }
        cin >> m;
        while(m--){
            count++;
            vector<int>nums = num;
            int check;
            cin >> check;
            int min1 = 9999, min2 = 9999;
            int min1P, min2P;
            for(int i = 0; i < nums.size(); i++){
                int temp = nums[i] - check;
                if(min1 > temp){
                    min1 = temp;
                    min1P = i;
                }
            }
            int tmpMin = nums[min1P];
            nums.erase(nums.begin()+min1P);
            for(int i = 0; i < nums.size(); i++){
                
                if(nums[i] < check && (nums[i] - check) > 0){
                    
                    int temp = nums[i] - check;
                    if(min2 > temp){
                        min2 = temp;
                        min2P = i;
                    }
                }
            }
            //nums.erase(nums.begin()+min2P);
            cout << "Case " << count << ": " << endl;
            cout << "Closest sum to " << check << " is " << tmpMin + nums[min2P] <<  "." << endl; 
            cout << tmpMin << " " << nums[min2P] << endl;
            
        }
    }
    
    return 0;
}