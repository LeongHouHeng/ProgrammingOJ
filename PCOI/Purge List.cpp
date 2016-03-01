#include <iostream>
#include <vector>
using namespace std;

int main(){
    
    int n;
    cin >> n;
    vector<int>nums;
    int num;
    for(int i = 0; i < n; i++){
        bool insert = true;
        cin >> num;
        for(int j = 0; j < nums.size(); j++){
            if(num == nums[j]){
                insert = false;
            }
        }
        if(insert){
            nums.push_back(num);
        }
    }
    for(int i = 0; i < nums.size(); i++){
        cout << nums[i] << " ";
    }
    cout << endl;
    return 0;
}