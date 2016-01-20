#include <iostream>
using namespace std;

int main(){
    
    int r, c, tmp;
    while(cin >> r >> c){
        int mn[100][100];
        tmp = r;
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                cin >> mn[i][j];
            }
        }
        
        for(int i = 0; i < c; i++){
            for(int j = 0; j < r; j++){
                cout << mn[j][i] << " ";
            }
            cout << endl;
        }
    }
    
    return 0;
}