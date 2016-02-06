#include <iostream>
#include <string>
#include "memory.h"

using namespace std;

char map[60][60];
int mapSatate[60][60];
int n, m;
bool fail = false;
int state = 0;      //1->top 2->right 3->bottom 4->left
char checkChar;
int current_x, current_y;
int ans = 0;
void dfs(int xn, int xm){
    if(map[xn][xm] == 'q'){
        fail = true;
        return;
    }
    if(map[xn][xm] != checkChar){
        return;
    }
    if(map[xn][xm] == checkChar){
        if(( (state == 1) && (xm != current_y) ) || ( (state == 2) && (xn != current_x) || ( (state == 3) && (xm != current_y )) || ((state == 4) && (xn != current_x)) ) ) )){
            return;
        }else{
            ans ++;
            map[xn][xm] = 'q';
            
        }
    }
}

int main(){
    memset(mapSatate, 0, sizeof(mapSatate));
    memset(map, 'p', sizeof(map));
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        string input;
        cin >> input;
        for(int j = 0; j < m; j++){
            map[i][j+1] = input[j];
            //cout << input[j] << endl;
        }
        
    }
    
    /*
        AAAAAA
        ABBCCB
        ABBBBB
        AAAAAA
    */
    
    //cout << map[1][5] << endl;
    while(!fail){
        for(int i = 1; i <= m; i++){
            checkChar = map[1][i];
            state = 1;
            current_x = 1;
            current_y = i;
            dfs(1, i);
            //cout << map[1][i] << endl;    //top AAAAAA
        }
        for(int i = 1; i <= n; i++){
            checkChar = map[i][m];
            state = 2;
            current_x = i;
            current_y = m;
            dfs(i, m);
            //cout << map[i][m] << endl;    //right ABBA
        }
        for(int i = 1; i <= n; i++){
            checkChar = map[i][1];
            state = 4;
            current_x = i;
            current_y = 1;
            dfs(i, 1);
            //cout << map[i][1] << endl;    //left AAAA
        }
        for(int i = 1; i <= m; i++){
            checkChar = map[n][i];
            state = 3;
            current_x = n;
            current_y = i;
            dfs(n, i);
            //cout << map[n][i] << endl;    //bottom AAAAAA
        }
    }
    
    return 0;
}