#include <iostream>
#include <string>
using namespace std;

char puzzle[5][5];

int main(){
    
    memset(puzzle, ' ', sizeof(puzzle));
    string input;
    int count = 0;
    while(input[0] != 'Z'){
        getline(cin, input);
        
        if(count == 4){
            for(int i = 0; i < 5; i++){
                for(int j = 0; j < 5; j++){
                    printf("%c ", puzzle[i][j]);
                }
                cout << endl;
            }
            //count = 0;
        }
        
        for(int i = 0; i < 5; i++){
            puzzle[count][i] = input[i];
        }
            
        count ++;
                
    }
    
    return 0;
}