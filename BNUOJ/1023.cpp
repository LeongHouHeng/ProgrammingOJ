#include <iostream>
#include <queue>
#include "memory.h"
using namespace std;

int map[200][200];

int main(){
    int k;
        cin >> k;
        for(int z = 0; z < k; z++){
            memset(map, -1, sizeof(map));
            int m, n;
            cin >> m >> n;
            for(int i = 1; i <= m; i++){
                for(int j = 1; j <= n; j++){
                    cin >> map[i][j];
                }
            }
            int i, j;
            cin >> i >> j;
            int p;  
            cin >> p;
            int maxHigh = 0;
            while(p--){
                int wx, wy;
                cin >> wx >> wy;
                
                int tmpHigh = map[wx][wy];
                if(tmpHigh > maxHigh){
                    maxHigh = tmpHigh;
                }
            }
            
            if(map[i][j] <= maxHigh){
                cout << "Yes" << endl;
            }else{
                cout << "No" << endl;
            }
            
        }
    return 0;
}