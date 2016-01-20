#include <iostream>
#include <queue>
using namespace std;

int ans;
int map[25][25];
bool visit[25][25][25];
int goX[]={0,0,1,-1};
int goY[]={1,-1,0,0};
int n, m;

struct Node{
    int x;
    int y;
    int step;
    int k;
};

void bfs(int k){
    Node node;
    node.x = 0;
    node.y = 0;
    node.step = 0;
    node.k = k;
    
    queue<Node>nodes;
    nodes.push(node);
    while(!nodes.empty()){
        Node next_node;        
        node = nodes.front();
        nodes.pop();
        
        if(node.x == m-1 && node.y == n-1){
            ans = node.step;
            return;
        }    
        
        if(node.k >= 0){
            for(int i = 0; i < 4; i++){
                next_node.x = node.x + goX[i];
                next_node.y = node.y + goY[i];
                next_node.step = node.step + 1;
                
                if(map[next_node.x][next_node.y]){
                    next_node.k = node.k-1;
                }else{
                    next_node.k = k;
                }
                if(next_node.x >= 0 && next_node.x <= m && next_node.y >= 0 && next_node.y <= n && !visit[next_node.x][next_node.y][next_node.k]){
                    if(next_node.k >= 0){
                        nodes.push(next_node);
                        visit[next_node.x][next_node.y][next_node.k] = true;
                    }
                }
            }
        }
    }
    ans = -1;
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