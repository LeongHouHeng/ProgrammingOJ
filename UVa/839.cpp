#include <iostream>
using namespace std;

bool slove(int &W){
    int W1, D1, W2, D2;
    bool b1 = true, b2 = true;
    cin >> W1 >> D1 >> W2 >> D2;
    if(!W1) b1 = slove(W1);
    if(!W2) b2 = slove(W2);
    W = W1 + W2;
    return b1 && b2 && (W1*D1 == W2 * D2);
}

int main(){
    int T, W;
    
    cin >>T;
    while(T--){
        if(slove(W))    cout << "YES" <<endl;
        else    cout << "NO" << endl;
        if(T) cout << endl;
    }
    
    return 0;
}