#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool pred(int i, int j){
    return i==j;
}

int main(){
    int n;
    while(cin >> n){
        vector<int> go, come;
        if(n == 0){
            break;
        }
        while(n--){
            int g, c;
            cin >> c >> g;
            go.push_back(g);
            come.push_back(c);
        }
        sort(go.begin(), go.end());
        sort(come.begin(), come.end());
        
        if(equal(go.begin(), go.end(), come.begin(), pred)){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
        
        
    }
    
    return 0;
}