#include <iostream>
#include <cctype>
#include "memory.h"
#include <stdio.h>
#include <string>
#include <sstream>
#include <vector>
#include <map>
using namespace std;

int matrix[100][100];
char matrixC[100][100];
//A = 65, Z = 90;
char charCount = 65;
int w, h;
int tmpCI;

void dfs(int x, int y, int ci){
    if(x > h || y > w || x < 0 || y < 0 || matrix[x][y] == 0 || matrix[x][y] == -1){
        return;
    }
    tmpCI += ci;
    matrix[x][y] = -1;
    matrixC[x][y] = charCount;
    dfs(x+1, y, 1);
    dfs(x, y+1, 30);
    dfs(x-1, y, 5);
    dfs(x, y-1, 70);
    dfs(x+1, y-1, 190);
    dfs(x-1, y+1, 1110);
    dfs(x+1, y+1, 1130);
    dfs(x-1, y-1, 1150);
}
void dfs2(int x, int y, int charC){
    if(x > h || y > w || x < 0 || y < 0 || matrix[x][y] == 0){
        return;
    }
    matrix[x][y] = 0;
    matrixC[x][y] = charC;
    dfs2(x+1, y, charC);
    dfs2(x, y+1, charC);
    dfs2(x-1, y, charC);
    dfs2(x, y-1, charC);
    dfs2(x+1, y-1, charC);
    dfs2(x-1, y+1, charC);
    dfs2(x+1, y+1, charC);
    dfs2(x-1, y-1, charC);
}

int main(){
    memset(matrix, 0, sizeof(matrix));
    memset(matrixC, '0', sizeof(matrixC));
    cin >> w >> h;
    string str;
    stringstream ss;
    int tmp = 0;
    for(int i = 0; i < h; i++){
        cin >> str;
        for(int j = 0; j < str.length(); j++){
            ss << str[j];
            ss >> matrix[i][j];
            ss.clear();
        }
    }
    map<int, char> ICmap;
    map<int, char>::iterator iter;
    
    for(int i = 0 ; i < h; i++ ){
        for(int j = 0; j < w; j++){
            if(matrix[i][j] == 1){
                tmpCI = 0;
                dfs(i, j, tmpCI);
                iter = ICmap.find(tmpCI);
                if(iter != ICmap.end()){
                    dfs2(i, j, ICmap[tmpCI]);
                }else{
                    ICmap[tmpCI] = charCount;   
                    charCount++;
                                     
                }
                
                
            }
        }
    }
    
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            cout << matrixC[i][j];
        }
        cout << endl;
    }
    
    
    return 0;
}