#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;

char map[4][4];
char mapTmp[4][4];

int step = 0;
int minStep = 999999;

bool check(){
    for(int r = 1; r <= 4; r++){
        for(int c = 1; c <= 4; c++){
            if(mapTmp[r][c] == '+')
                return false;
        }
    }
    return true;
}

void dfs(int i, int j){
    if(i < 1 || i > 4 || j < 1 || j > 4){
        return;
    }
    
    if(mapTmp[i][j] == '+'){
        step++;
        mapTmp[i][j] = '-';
    }else{
        step++;
        mapTmp[i][j] = '+';
    }
    dfs(i+1, j);
    dfs(i, j+1);
    dfs(i-1, j);
    dfs(i, j-1);
    
}

void travel(int i, int j){
    int tmpI = i;
    step++;
    while(tmpI <= 4){
        if(mapTmp[tmpI][j] == '+'){
            mapTmp[tmpI][j] = '-';   
        }else{
            mapTmp[tmpI][j] = '+';
        }
        tmpI++;
    }
    tmpI = i-1;
    while(tmpI >= 1){
        if(mapTmp[tmpI][j] == '+'){
            mapTmp[tmpI][j] = '-';
        }else{
            mapTmp[tmpI][j] = '+';
        }
        tmpI--;
    }
    int tmpJ = j;
    while(tmpJ <= 4){
        if(mapTmp[i][tmpJ] == '+'){
            mapTmp[i][tmpJ] = '-';
        }else{
            mapTmp[i][tmpJ] = '+';
        }
        tmpJ ++;
    }
    tmpJ = j-1;
    while(tmpJ >= 1){
        if(mapTmp[i][tmpJ] == '+'){
            mapTmp[i][tmpJ] = '-';
        }else{
            mapTmp[i][tmpJ] = '+';
        }
    }
}

void slove(int i, int j){
    for(int i = 1; i <=4; i++){
        for(int r = 1; r <= 4; r++){
            if(mapTmp[i][r] == '-'){
                resetArray();
                travel(i, r);
                if(step < minStep){
                    minStep = step;
                }
            }
        }
    }
}

void resetArray(){
    for(int i = 1; i <= 4; i++){
        for(int j = 1; j <=4; j++){
            mapTmp[i][j] = map[i][j];
        }
    }
}



int main(){
    
    string input;
    for(int i = 1; i <= 4; i++){
        cin >> input;
        for(int r = 0; r < input.length(); r++){
            map[i][r+1] = input[r];
        }
    }
    
    /*
    if(step < minStep){
        minStep = step;
    }
    */
    
    
    for(int i = 1; i <=4; i++){
        for(int r = 1; r <= 4; r++){
            if(map[i][r] == '-'){
                resetArray();
                //dfs(i, r);
                slove(i, r);
                //travel(i, r);
                if(step < minStep){
                    minStep = step;
                }
            }
        }
    }
    
    /*
    for(int i = 1; i <= 4; i++){
        for(int j = 1; j <= 4; j+){
            if(mapTmp[i][j])
        }
    }
    */
    cout << minStep << endl;
    
    
    
    return 0;
}