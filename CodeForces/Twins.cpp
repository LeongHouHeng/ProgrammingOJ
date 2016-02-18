#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(int &a, int&b){
    return a > b;
}

int main(){
    vector<int> coins;    
    int n, tmp;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> tmp;
        coins.push_back(tmp);
    }
    sort(coins.begin(), coins.end(), cmp);
    int sum = 0, count = 0, allSum = 0;
    for(int i = 0; i < n; i++){
        allSum += coins[i];
    }
    for(int i = 0; i < n; i++){
        count++;
        sum += coins[i];
        if(sum > allSum/2){
            break;
        }
    }
    cout << count << endl;
    
    return 0;
}