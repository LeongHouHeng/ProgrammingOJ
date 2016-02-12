#include <iostream>
using namespace std;

int fs(int i){
    if(i == 0 || i == 1){
        return i;
    }
    return fs(i-1) + fs(i-2	 );
}

int main(){
    int n;
    cin >> n;
    cout << fs(n) << endl;
    return 0;
}