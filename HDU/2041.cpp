#include <iostream>
using namespace std;

int main(){
    
    int n;
    while(cin >> n){
        int s[50];
        s[1] = 1;
        s[2] = 1;
        for(int i = 3; i <= 40; i++){
            s[i] = s[i-1] + s[i-2];
        }
        while(n--){
            int m;
            cin >> m;
            cout << s[m] << endl;
        }
    }
    
    return 0;
}