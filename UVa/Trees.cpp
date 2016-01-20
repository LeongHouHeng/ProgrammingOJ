#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <queue>
using namespace std;
char s[255]

struct Node{
    bool have_value;
    int v;
    Node *left, *right;
    Node():have_value(false),left(NULL),right(NULL){}
};

Node* newnode(){
    Node *u = &node[++cnt];
    u->left = u->right = NULL;
    u->have_value = false;
    return u;
}

void remove_tree(Node *u){
    if(u == NULL)   return;
    remove_tree(u->left);
    remove_tree(u->right);
    delete u;
}

void addNode(int v, char *s){
    int n = strlen(s);
    Ndoe *u = root;
    for(int i = 0; i < n; i++){
        if(s[i] == 'L'){
            if(u->left == NULL)
                u->left = newnode();
            u = u->left;
        }else if(s[i] == 'R'){
            if(u->right == NULL)
                u->right = newnode();
            u = u->right;
        }
        
        if(u->have_value)
            failed = true;
        u->v = v;
        u->have_value = true;
    }
}

bool bsf(vector<int> &ans){
    queue<Node*> q;
    ans.clear();
    q.push(root);
    while(!q.empty()){
        Node *u = q.front();
        q.pop();
        if(!u->have_value)
            return false;
        ans.push_back(u->v);
        if(u->left != NULL)
            q.push(u->left);
        if(u->right != NULL)
            q.push(u->right);
    }
    return true;
}

bool read_input(){
    failed = false;
    remove_tree(root);
    root = newnode();
    while(true){
        if(scanf("%s", s) != 1) return false;
        if(!strcmp(s, "()"))    break;
        int c;
        sscanf(&s[1],"%d", &v);
        addNode(v, strchr(s, ',')+1);
    }
    return true;
}

const int root = 1;
int cnt;
int left[255],right[255];
void newtree(){
    left[root] = right[root] = 0;
    have_value[root] = false;
    cnt = root;
}

int newnode(){
    int u = ++cnt;
    left[u] = right[u] = 0;
    have_value[root] = false;
    return u;
}