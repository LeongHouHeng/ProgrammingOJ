#include <iostream>
#include <queue>
#include <string.h>
#include <stdio.h>
using namespace std;

char s[225];
bool fail;
struct Node{
    bool have_value;
    int v;
    Node* left;
    Node* right;
    Node():have_value(false),left(NULL), right(NULL){};
};

Node *root;
Node* newnode(){  return new Node();  }

void addnode(int v, char* s){
    int n = strlen(s);
    Node* u = root;
    for(int i = 0; i < n; i++){
        if(s[i] == 'L'){
            if(u->left == NULL) u->left = newnode();
            u = u->left;
        }else{
            if(u->right == NULL)    u->right = newnode();
            u = u->right;
        }
    }
    if(u->have_value)fail = true;
    u->v = v;
    u->have_value = true;
}

void removeTree(Node *u){
    if(u == NULL)
        return;
    
    removeTree(u->left);
    removeTree(u->right);
    delete u;
}

bool read_input(){
    fail = false;
    removeTree(root);
    root = newnode();
    
    while(true){
        if(scanf("%s", s) != 1) return false;
        if(!strcmp(s, "()"))    break;
        int v;
        sscanf(&s[1], "%d", &v);
        addnode(v, strchr(s, ',')+1);
    }
    return true;
}

bool bfs(vector<int>& ans){
    queue<Node*> q;
    ans.clear();
    q.push(root);
    while(!q.empty()){
        Node *u = q.front();
        q.pop();
        if(!u->have_value)   return false;
        ans.push_back(u->v);
        if(u->left != NULL) q.push(u->left);
        if(u->right != NULL)    q.push(u->right);
        
    }
    
    return true;
}

int main(){
    
    vector<int> ans;
    while(read_input()){
        if(!bfs(ans))   fail = 1;
        if(fail)    cout << "not complete" << endl;
        else{
            for(int i = 0; i < ans.size(); i++){
                if(i != 0){
                    cout << " ";
                }
                cout << ans[i];
            }
            cout << endl;
        }
    }
    
    return 0;
}