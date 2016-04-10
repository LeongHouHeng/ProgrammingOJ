    #include <iostream>
    #include <stdlib.h>
    #include "memory.h"
    using namespace std;
    int bomb;
    int killed[1025][1025];

    int main(){
        int scen;
        cin >> scen;
        while(scen--){
            memset(killed, 0, sizeof(killed));
            cin >> bomb;
            int rats;
            cin >> rats;
            while(rats--){
                int x, y, popu;
                cin >> x >> y >> popu;
                for(int i=x-bomb ; i<=x+bomb ; i++)
                    for(int j=y-bomb ; j<=y+bomb ; j++)
                        if(i >= 0 && i <= 1024 && j >= 0 && j <= 1024) 
                            killed[i][j] += popu;
            }
            int tmp = 0, tmpX, tmpY;
            for(int i=0 ; i<=1024 ; i++){
                for(int j=0 ; j<=1024 ; j++) {
                    if(killed[i][j] > tmp) {
                        tmp = killed[i][j];
                        tmpX = i, tmpY = j;
                    }
                }
            }
            cout << tmpX << " " << tmpY << " " << tmp << endl;
        }
    
        return 0;
    }