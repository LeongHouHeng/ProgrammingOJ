#include <iostream>
using namespace std;

int dp[100] = {1, 1, 2};

/* top down */
int slove(int n){
    if(dp[n] != 0){
        return dp[n];
    }
    dp[n] = slove(n-1) + slove(n-2);
    return dp[n];
}

int dpb[101];

void bottomUP(){
    dpb[1] = 1;
    dpb[2] = 2;
    
    for(int i = 3; i < 101; i++){
        dpb[i] = dpb[i-1] + dpb[i-2];
    }
}

int main(){
    int n;
    cin >> n;
    bottomUP();
    //cout << slove(n) << endl;
    cout << dpb[n] << endl;
    return 0;
}