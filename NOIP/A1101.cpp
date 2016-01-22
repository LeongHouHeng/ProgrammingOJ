#include <iostream>
using namespace std;

int map[24][24];
int n, i, j;

void slove(int x, int y){
    if(x == n || x == 0 || y == n || y == 0){
        if(x == 0 || y == 0)
            return;
        
        cout << "(" << x << "," << y << ")" << endl;
        n--;
        return;
    }
    
    slove(x+1, y);  slove(x-1, y);
    slove(x, y+1);  slove(x, y-1);
    slove(x-1, y-1);    slove(x+1, y+1);
    slove(x+1, y-1);    slove(x-1, y+1);
    
    
}

int main(){
    while(cin >> n >> i >> j){
        slove(i, j);
    }
}