#include <iostream>
using namespace std;

int dp[101][3];
void init(){
    dp[1][0] = dp[1][1] = dp[1][2] = 1;
}

//top down
int f(int n, int m){
    if(dp[n][m] != 0)
        return dp[n][m];
    if(m==0)
        dp[n][m] = f(n-1, 0) + f(n-1, 1) + f(n-1, 2);
    if(m==1)
        dp[n][m] = f(n-1, 0) + f(n-1, 1);
    if(m==2)
        dp[n][m] = f(n-1, 0) + f(n-1, 2);
        
    return dp[n][m];
}

//bottom up
void build(){
    dp[1][0] = dp[1][1] = dp[1][2] = 1;
    for(int i = 2; i < 101; i++){
        dp[i][0] = dp[i-1][0] + dp[i-1][1] + dp[i-1][2];
        dp[i][1] = dp[i-1][0] + dp[i-1][1];
        dp[i][2] = dp[i-1][0] + dp[i-1][2];
    }
}

int main(){
    
    
    return 0;
}