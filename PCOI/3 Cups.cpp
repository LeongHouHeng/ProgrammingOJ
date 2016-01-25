#include <iostream>
using namespace std;

int main(){
    int T;
    cin >> T;
    char state = 'M';
    while(T--){
        char pos1, pos2;
        cin >> pos1 >> pos2;
        if(state == pos1){
            state = pos2;
        }else if(state == pos2){
            state = pos1;
        }
    }
    
    switch(state){
        case 'M':
            cout << "Middle" << endl;
            break;
        case 'R':
            cout << "Right" << endl;
            break;
        case 'L':
            cout << "Left" << endl;
            break;
    }
    
    return 0;
}