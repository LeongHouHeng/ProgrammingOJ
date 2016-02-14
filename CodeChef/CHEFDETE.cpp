#include <iostream>
#include "memory.h"
using namespace std;

int main(){
    int n;
    while(cin >> n){
        bool N[10000];
        memset(N, true, sizeof(N));
        if(n > 10000){
            break;
        }
        for(int i = 0; i < n; i++){
            int num;
            cin >> num;
            if(N[num] ==true)
                N[num] = false;
        }
        for(int i = 1; i <= n; i++){
            if(N[i] == true){
                cout << i << " ";
            }
        }
        cout << endl;
    }
    return 0;
}