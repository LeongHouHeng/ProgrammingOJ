#include <iostream>
#include <queue>
#include <string.h>
#include <stdio.h>
using namespace std;

char s[225];

struct Node{
    bool have_value;
    Node* left;
    Node* right;
    Node():have_value(false),left(NULL), right(NULL){};
};

Node* newnode(){  return new Node();  }

void addnode(){
    
}

bool read_input(){
    while(true){
        if(scanf("%s", s) != 1) return false;
        if(!strcmp(s, "()"))    break;
        int v;
        sscanf(&s[1], "%d", &v);
        addnode(v, strchr(s, ',')+1);
    }
}

bool bfs(){
    
    
    
}

int main(){
    
    vector<int> ans;
    while(read_input()){
        
    }
    
    return 0;
}