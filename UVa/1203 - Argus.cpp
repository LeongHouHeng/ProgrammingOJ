#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

struct argu{
    int q_num;
    int period;
    int timer;
    
};

class cmp{
    public:
    bool operator() (argu a, argu b){
        if(a.timer == b.timer)
            return a.q_num < b.q_num;
        else
            return a.timer < b.timer;
    }
};

int main(){
    priority_queue<argu, vector<argu>, cmp> bq;
    string regist;
    argu argus;        

    while(cin >> regist){
        if(regist[0] == '#')
            break; 
        
        argus.timer = 0;
        cin >> argus.q_num >> argus.period;
        bq.push(argus);
    }
    
    int K;
    cin >> K;
    while(K--){
        argu tmp = bq.top();
        bq.pop();
        cout << tmp.q_num << endl;
        argus.q_num = tmp.q_num;
        tmp.timer = tmp.timer+tmp.period;
        argus = tmp; 
        bq.push(argus);
        
    }
    
    return 0;
}