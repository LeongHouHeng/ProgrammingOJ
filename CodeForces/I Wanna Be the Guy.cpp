#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<bool> level;
    for(int i = 0; i < n; i++){
        level.push_back(false);
    }
    int x;
    cin >> x;
    while(x--){
        int tmp;
        cin >> tmp;
        level[tmp-1] = true;
    }
    int y;
    cin >> y;
    while(y--){
        int tmp;
        cin >> tmp;
        level[tmp-1] = true;
    }
    bool succ = true;
    for(int i = 0; i < level.size(); i++){
        if(level[i] == false){
            succ = false;
        }
    }
    
    if(succ){
        cout << "I become the guy." << endl;
    }else{
        cout << "Oh, my keyboard!" << endl;
    }
    return 0;
}