#include <iostream>
using namespace std;

int nums[] = {4, 7, 44, 47, 74, 77, 444, 447, 477, 474, 747, 777, 744};

int main(){
    int input;
    cin >> input;
    bool flat = false;
    for(int i = 0; i < 13; i++){
        if(input % nums[i] == 0){
            flat = true;
        }
    }
    
    if(flat){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
    
    return 0;
}