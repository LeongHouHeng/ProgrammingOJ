#include <iostream>
#include <vector>

using namespace std;
vector<int> milks;
int n, m;

int binarysearch(int left, int right){
    while(left < right){
        int mid = (left+right) >> 1;
        int max = 0;
        int containers = 0;
        for(int i = 0; i < milks.size(); i++){
            max += milks[i];
            if(max > mid){
                max = milks[i];
                containers++;
            }else if(max == mid){
                max = 0;
                containers++;
            }
        }
        if(max > 0){
            containers++;
        }
        if(containers > m){
            left = mid+1;
        }else{
            right = mid;
        }
    }
    return left;
}

int main(){
    
    while(cin >> n >> m){
        int tmp;
        int left = 0, right = 0;
        
        for(int i = 0; i < n; i++){
            cin >> tmp;
            milks.push_back(tmp);
            if(tmp > left) left = tmp;
            right += tmp;
        }
        cout << binarysearch(left, right) << endl;
        milks.clear();
    }
    return 0;
}