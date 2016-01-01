#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    double v, r;
    while(cin >> v >> r){
        cout << fixed << setprecision(4) << v/r*1000 << endl;
    }
    
}