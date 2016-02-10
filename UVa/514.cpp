#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main(){
    int n;
    while(cin >> n){
        if(n == 0){
            break;
        }
        stack<int>s;
        vector<int> t;
        int countA = 1, countB = 1;
        t.push_back(0);
        int tmp;
        for(int i = 1 ; i <= n; i++){
            cin >> tmp;
            t.push_back(tmp);
        }
        bool fail = false;
        while(countB <= n){
            if(countA ==t[countB]){
                countA++;
                countB++;
                
            }else if(!s.empty() && s.top() == t[countB]){
                s.pop();
                countB++;
            }else if(countA <= n){
                s.push(countA++);
            }else{
                fail = true;
                break;
            }
        }
        cout << (fail?"NO":"YES") << endl;
        
    }
    
    return 0;
}