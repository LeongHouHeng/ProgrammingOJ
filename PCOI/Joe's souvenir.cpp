#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> peanuts;
int ans = 0;
void slove(int price, int left, int right){
    while(left <= right){
        int mid = (left + right) / 2;   //cout << "mid: " << mid << endl;
        if(price == peanuts[mid]){
            ans = peanuts[mid];
            return;
        }else if(price > peanuts[mid]){
            left = mid+1;
        }else if(price < peanuts[mid]){
            right = mid-1;
        }
    }
    ans = peanuts[left-1] >= 0 ? peanuts[left-1] : 0;
    
}

int main(){
    int n;
    int tmp;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> tmp;
        peanuts.push_back(tmp);
    }
    sort(peanuts.begin(), peanuts.end());
    int m;
    cin >> m;
    while(m--){
        int price;
        cin >> price;
        slove(price, 0, peanuts.size()-1);
        cout << ans << endl;
        ans = 0;
    }
    
    return 0;
}