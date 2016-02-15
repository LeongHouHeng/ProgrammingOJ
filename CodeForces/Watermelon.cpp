#include <iostream>
using namespace std;

int main(){
    int w;
    while(cin >> w){
        if(w % 2 || w <= 2)
            cout << "NO" << endl;
        else
            cout << "Yes" << endl;
        
    }
    
    
    return 0;
}