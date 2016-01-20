#include <iostream>
#include <queue>
#include <vector>
#include "memory.h"

using namespace std;

int map[30][30];
bool visit[30][30][30];
int n, m;
int ans;
int goToX[] = {0, 0, 1, -1};
int goToY[] = {1, -1, 0, 0};

struct Node{
    int x;
    int y;
    int k;
    int step;
};

void bfs(int k){
    Node ns;
    queue<Node> nodes;
    ns.x = 0;
    ns.y = 0;
    ns.k = k;
    ns.step = 0;
    nodes.push(ns);
    while(!nodes.empty()){
        ns = nodes.front();
        nodes.pop();
        if(ns.x == m-1 && ns.y == n-1){
            ans = ns.step;
            return;
        }
     Node visited;
     if(ns.k >= 0){
        for(int i = 0; i < 4; i++){
            visited.x = ns.x + goToX[i];
            visited.y = ns.y + goToY[i];
            visited.step = ns.step+1;
            if(map[visited.x][visited.y]){
                visited.k = ns.k-1;
            }else{
                visited.k = k;
            }
                        
            if(visited.x >= 0 && visited.x < m && visited.y >= 0 && visited.y < n && !visit[visited.x][visited.y][visited.k]){
                if(visited.k >= 0){
                    nodes.push(visited);
                    visit[visited.x][visited.y][visited.k] = true;
                    }
                }
            }
                    
        }
    }
    ans = -1 ;   
}

int main(){
    
    int dataSetSize;
    while(cin >> dataSetSize){
        while(dataSetSize --){
            memset(map, 0, sizeof(map));
            memset(visit, false, sizeof(visit));
            int k;
            cin >> m >> n;
            cin >> k;
            for(int i = 0; i < m; i++){
                for(int j = 0; j < n; j++){
                    cin >> map[i][j];
                }
            }
            bfs(k);
            cout << ans << endl;
        }
        
    }
    
    return 0;
}