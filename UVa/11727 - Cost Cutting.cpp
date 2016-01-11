#include <iostream>

using namespace std;

int main(){
    int T;
    while(cin >> T){
        for(int i = 1; i <= T; i++){
            int a, b, c;
            cin >> a >> b >> c;
            cout << "Case " << i << ": " << (a<b?(b<c?b:a<c?c:a):(b>c?b:a>c?c:a)) << endl;
           
        }
        
    }
    
    return 0;
}