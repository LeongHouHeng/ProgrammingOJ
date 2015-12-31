#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include "memory.h"
using namespace std;

char puzzle[5][5];
int spaceX, spaceY;

void above(int x, int y){
    
    char tmp = puzzle[x][y];
    puzzle[x][y] = puzzle[x-1][y];
    puzzle[x-1][y] = tmp;
    spaceX = x-1;
    spaceY = y;
    
}

void behind(int x, int y){
    char tmp = puzzle[x][y];
    puzzle[x][y] = puzzle[x+1][y];
    puzzle[x+1][y] = tmp;
    spaceX = x+1;
    spaceY = y;
}

void left(int x, int y){
    char tmp = puzzle[x][y];
    puzzle[x][y] = puzzle[x][y-1];
    puzzle[x][y-1] = tmp;
    spaceX = x;
    spaceY = y-1;
}

void right(int x, int y){
    char tmp = puzzle[x][y];
    puzzle[x][y] = puzzle[x][y+1];
    puzzle[x][y+1] = tmp;
    spaceX = x;
    spaceY = y+1;
}

int main(){
    
    memset(puzzle, ' ', sizeof(puzzle));
    string input;
    int count = 0;
    int round = 0;
    while(input[0] != 'Z'){
        //cin.ignore();
        getline(cin, input);
        
        for(int i = 0; i < 5; i++){
            puzzle[count][i] = input[i];
            if(input[i] == ' '){
                spaceX = count; 
                spaceY = i;                
            }
        }
        count ++;
        if(count > 4){
         
            char c;
            while((c = getchar()) != '0'){
                switch(c){
                    case 'A':
                        above(spaceX, spaceY);
                        //cout << "-----" << spaceX << " " << spaceY << endl;
                        break;
                    case 'B':
                        behind(spaceX, spaceY);
                        break;
                    case 'L':
                        left(spaceX, spaceY);
                        break;
                    case 'R':
                        right(spaceX, spaceY);
                        break;
                }
            }
            
            cout << "Puzzle #" << ++round  << ":"<< endl;   
                for(int i = 0; i < 5; i++){
                    for(int j = 0; j < 5; j++){
                        printf("%c ", puzzle[i][j]);
                    }
                    printf("\n");
                }
            cout << endl;
            //count = 0;
        }           
    }
    
    return 0;
}