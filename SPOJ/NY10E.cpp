#include <iostream>
#include <memory.h>
using namespace std;
long long int dp[65][10];

int main(){
    int n;
    while(cin >> n){
        
        for(int i = 0; i < 10; i++){
            dp[0][i] = 1;
        }
        for(int i = 1; i <= 65; i++){
            for(int j = 0; j < 10; j++){
                for(int k = 0; k <= j; k++){
                    dp[i][j] += dp[i-1][k];
                }
            }
        }
        while(n--){
            int p, num;
            cin >> p >> num;
            cout << p << " " << dp[num][9] << endl;
        }
    }
    return 0;
}