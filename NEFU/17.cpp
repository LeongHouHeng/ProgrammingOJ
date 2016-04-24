#include <iostream>
#include <algorithm>
#include <memory.h>
using namespace std;

int main(){
    int n;
    while(cin >> n){
        int tg[101][101];
        memset(tg, 0, sizeof(tg));
        cin >> tg[1][1];
        for(int i = 2; i <= n; i++){
            for(int j = 1; j <= i; j++){
                cin >> tg[i][j];
                tg[i][j] = max(tg[i-1][j], tg[i-1][j-1]) + tg[i][j];
            }
        }
        int max = 0;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(max < tg[i][j]){
                    max = tg[i][j];
                }
            }
        }
        cout << max << endl;
    }
    return 0;
}