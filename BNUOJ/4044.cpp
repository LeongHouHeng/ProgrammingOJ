#include <iostream>
#include <string>
using namespace std;

struct Node{
    char data;
    Node* lchild;
    Node* rchild;
    Node():lchild(NULL), rchild(NULL){};
};

Node* build(string pre, string in, int length){
    Node *node = new Node();
    node->data = pre[0];
    int pos = in.find(pre[0]);
    if(pos > 0){
        node->lchild = build(pre.substr(1, pos), in.substr(0, pos), pos);
    }
    if(length-1-pos > 0){
        node->rchild = build(pre.substr(pos+1), in.substr(pos+1), length-1-pos);
    }
    return node;
}

void post(Node *node){
    if(node->lchild != NULL){
       post(node->lchild); 
    }
    if(node->rchild != NULL){
        post(node->rchild);
    }
    cout << node->data;
}

int main(){
    
    string pre, in;
    cin >> pre >> in;
    Node *root = build(pre, in, in.length());
    post(root);
    cout << endl;
    return 0;
}