#include <iostream>
using namespace std;

int main(){
    int a, b, k;
    cin >> a >> b >> k;
    int sum = 0;
    for(int i = a; i <= b; i++){
        if(i % 4 == 0){
            sum += i;
        }
    }
    cout << sum << endl;
    
}