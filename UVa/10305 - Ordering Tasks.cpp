#include <iostream>

using namespace std;

int c[100];
int sorted[100];
int G[100][100];
int t, n, m;

bool dfs(int k){
    c[k] = -1;
    for(int l = 0; l < n; l++)  
        if(G[k][l]){
            if(c[l] < 0)    return false;
            else if(!c[l] && !dfs(l))   return false; 
        }
        
    c[k] = 1;
    sorted[--t] = k;
    return true;
}

bool toposort(){
    t = n;
    memset(c, 0, sizeof(c));
    for(int k = 0; k < n; k++){
        if(!c[k]){
            if(!dfs(k)){
                return false;
                
            }
        }
    }
    return true;
}

int main(){
    
    while(cin >> n >> m){
        memset(sorted, 0, sizeof(sorted));
        for(int a = 0; a < m; a++){
            int i, j;
            cin >> i >> j;
            G[i][j] = 1;
        }
        if(toposort()){
            for(int i = 0; i < n-1; i++){
                cout << sorted[i]+1 << " ";
            }
            cout << sorted[n-1]+1 << endl;
        }
    }
    
    return 0;
}