#include <iostream>
#include "memory.h"
#include <vector>
#include <list>
using namespace std;

int map[100];
int ans[100];
bool visit[100];
int at[100][100];
int bt[100][100];
int a, m;
int cnt;
void dfs(int k, int u){
    if(u == a){
        cnt++;
        for(int i = 0; i <k; i++){
            if(i){
                cout << " ";
            }
            cout << ans[i];
        }
        cout << endl;
        return;
    }
    for(int i = 1; i <= m; i++){
        if(map[i]){
            continue;
        }
        if(!at[u][i]){
            continue;
        }
        if(!bt[i][a]){
            continue;
        }
        map[i] = 1;
        ans[k] = i;
        dfs(k+1, i);
        map[i] = 0;
    }
}

int main(){

    int roundCnt = 0;
    while(cin >> a){
        roundCnt++;
        int x, y;
        memset(map, 0, sizeof(map));
        memset(visit, false, sizeof(visit));
        memset(at, 0, sizeof(at));
        memset(bt, 0, sizeof(bt));
        while(cin >> x >> y){
            if(x == 0 && y == 0)
                break;
                
            m = (m > (x>y?x:y) ? m : (x>y?x:y));
            at[x][y] = at[y][x] = 1;
            bt[x][y] = bt[y][x] = 1;
        }
        
        for(int k = 1; k <= m; k++){
            for(int i = 1; i <= m; i++){
                for(int j = 1; j <= m; j++){
                    if(bt[i][k] && bt[k][j]){
                        bt[i][j] = 1;
                    }
                }
            }
        }
        cnt = 0;
        cout << "CASE " << roundCnt << ":" << endl;
        map[1] = 1;
        ans[0] = 1;
        dfs(1, 1);
        cout << "There are " << cnt << " routes from the firestation to streetcorner " << a << ".";
        cout << endl;
    }
    
    return 0;
}