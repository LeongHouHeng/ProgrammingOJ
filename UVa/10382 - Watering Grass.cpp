#include <iostream>
#include "memory.h"
using namespace std;

bool grass[100];

bool check(int pos, int radius){
    bool state = true;
    for(int i = pos; i < pos+radius; i++){
        if(grass[i] == true){
            state = false;
        }
    }
    return state;
}

int main(){
    int n, l, w;
    while(cin >> n >> l >> w){
        memset(grass, false, sizeof(grass));
        int count = 0;
        while(n--){
            int pos, radius;
            cin >> pos >> radius;  
            if(check(pos, radius))
                for(int i = pos; i < pos+radius; i++){
                    grass[i] = true;
                }

        }
        cout << count << endl;
    }
    return 0;
}