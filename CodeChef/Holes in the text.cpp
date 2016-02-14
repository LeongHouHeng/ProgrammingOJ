#include <iostream>
#include <string>
using namespace std;
char tex[] = {'A', 'B', 'D', 'O', 'P', 'Q', 'R', 'a', 'b', 'd', 'e', 'g', 'o', 'p', 'q'};
int main(){
    
    int n;
    while(cin >> n){
        while(n--){
            string input;
            int count = 0;
            cin >> input;
            for(int i = 0; i < input.length(); i++){ 
                for(int j = 0; j < sizeof(tex); j++){
                    if(input[i] == tex[j]){
                        count++;
                        if(input[i] == 'B'){
                            count++;
                        }
                    }
                }
            }
            cout << count << endl;
        }
    }
    
    return 0;
}