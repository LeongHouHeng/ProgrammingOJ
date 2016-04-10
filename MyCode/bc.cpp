#include <iostream>
using namespace std;
int solution[5];
void bc(int n){
    if(n == 5){
        for(int i = 0; i < 5; i++){
            cout << solution[i] << " ";
        }
        cout << endl;
        
        return;
    }
    for(int i = 1; i <= 10; ++i){
        solution[n] = i;
        bc(n+i);
    }
}

int main(){
    
    bc(0);
    
    return 0;
}