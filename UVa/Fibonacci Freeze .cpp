#include <iostream>
#include <fstream>
#include <memory.h>
using namespace std;
int f[5001][5001] = {0};

int main(){
    f[1][0] = 1;
    for(int i = 2; i <= 5000; i++){
        for(int j = 0; j < 5001; j++){
            f[i][j] += f[i-1][j] + f[i-2][j];
            f[i][j+1] += f[i][j]/10;
            f[i][j] %= 10;
        }
    }
    int n;
    while(cin >> n){
        cout << "The Fibonacci number for " << n << " is "; 
        int i;
        for( i = 5000 ; i >= 0 ; i-- )
            if( f[n][i] )
             break;
        if( i == -1 )
          cout << 0;
        else
          for( ; i >= 0 ; i-- )
            cout << f[n][i];
        cout << endl;
    }
    return 0;
}