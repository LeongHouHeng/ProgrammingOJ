#include <iostream>
#include <vector>
#include <algorithm>
#include "memory.h"
using namespace std;

bool visit[510];
bool map[510][510];
int n, m, a, b;

void dfs(int i){
    for(int j = 0; j < n; j++){
        if(map[i][j] && !visit[i]){
            visit[i] = true;
            dfs(j);
            
        }
    }
}

int main(){
        cin >> n >> m;
        memset(visit, false, sizeof(visit));
        memset(map, false, sizeof(map));
        
        int k;
        cin >> k;
        while(k--){
            cin >> a >> b;
            map[a-1][b-1] = true;
            map[b-1][a-1] = true;
        }
        dfs(m-1);
        vector<int>answer;
        int count = 0;
        for(int i = 0; i < n; i++){
            if(visit[i] == false){
                answer.push_back(i+1);
                count ++;
                
            }
        }
        
        cout << count << endl;
        if(count != 0){
            sort(answer.begin(), answer.end());
            for(int i = 0; i < answer.size(); i++){
                cout << answer[i] << " ";
            }
            cout << endl;
        }
        
    return 0;
}