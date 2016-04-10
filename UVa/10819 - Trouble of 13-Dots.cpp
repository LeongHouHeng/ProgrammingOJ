#include <iostream>
#include "memory.h"
using namespace std;
int p[4001], f[4001];
int dp[110][11000];
int n, m;

int sf(int i, int w){
    if(w > m && m <= 1800)
        return -1000;
    
    if(w > m+200)
        return -1000;
    
    if(i == n){
        if(w > m && w <= 2000)
            return -1000;
        
        return 0;
    }
    
    if(dp[i][w] != -1){
        return dp[i][w];
    }
    
    return dp[i][w] = max(sf(i+1, w), sf(i+1, w+p[i]) + f[i]);
}

int main(){
    
    while(cin >> m >> n){
        memset(p, 0, sizeof(p));
        memset(f, 0, sizeof(f));
        memset(dp, -1, sizeof(dp));
        for(int i = 0; i < n; i++){
            int ip, fi;
            cin >> ip >> fi;
            p[i] = ip;
            f[i] = fi;
        }
        cout << sf(0, 0) << endl;
        
    }
    
    return 0;
}