#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <list>
#include <memory.h>
using namespace std;

char map[255][255];
int nodeNum;
int v[255];
int q[255][255];
int main(){
    
    int slept;
    while(cin >> slept){
        memset(map, 0, sizeof(map));
        memset(v, 0, sizeof(v));
        memset(q, 0, sizeof(q));
        int con;
        cin >> con;
        string str;
        cin >> str;
        for(nodeNum = 0; nodeNum < str.length(); nodeNum++){
            q[nodeNum][0] = str[nodeNum];
            q[nodeNum][1] = 0;
            v[str[nodeNum]] = 4;
        }
        while(con--){
            string input;
            cin >> input;
            map[input[0]][input[1]] = 1;
            map[input[1]][input[0]] = 1;
            
        }
        for(int i = 0 ; i < nodeNum; i++){
            for(int j = 'A'; j <= 'Z'; j++){
                if(v[j] < 3 && map[q[i][0]][j]){
                    ++v[j];
                }
                if(v[j]==3){
                    q[nodeNum][0] = j;
                    q[nodeNum][1] = q[i][1] + 1;
                    ++nodeNum;
                    ++v[j];
                }
            }
        }
        if(nodeNum < slept)
            cout << "THIS BRAIN NEVER WAKES UP" << endl;
        else
            cout << "WAKE UP IN, " << q[nodeNum-1][1] << ", YEARS" << endl;
    }
    
    return 0;
}