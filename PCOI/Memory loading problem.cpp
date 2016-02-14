#include <iostream>
#include <queue>
using namespace std;

int totalMemory(queue<int> &memories){
    int total = 0;
    for(queue<int> tmp = memories; !tmp.empty(); tmp.pop()){
        total += tmp.front();
    }
    return total;
}

int main(){
    int processes = 10000;
    int count = 0;
    queue<int> memories;
    while(!cin.eof()){
        char command;
        int memory;
        cin >> command;
        if(command == 'E'){
            cin >> memory;
            memories.push(memory);
            count ++;
            cout << totalMemory(memories) << endl;
        }else if(command == 'D'){
            memories.pop();
            count ++;
            cout << totalMemory(memories) << endl;
        }else{
            processes++;
            continue;
        }
    }
    
    
    return 0;
}