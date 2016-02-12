#include <iostream>
#include <string>

using namespace std;

struct Node{
    char data;
    Node *lchild;
    Node *rchild;
    Node(){
        lchild = NULL;
        rchild = NULL;
    }  
};

Node* buildTree(string preorder, string inorder, int length){
    Node *current_node = new Node();
    current_node->data = preorder[0];
    int pos = inorder.find(preorder[0]);
    if(pos > 0){
        current_node->lchild = buildTree(preorder.substr(1, pos), inorder.substr(0, pos), pos);
    }
    if(length-1-pos){
        current_node->rchild = buildTree(preorder.substr(pos+1), inorder.substr(pos+1), length-1-pos);
    }
    return current_node;
}

void postorder(Node* root){
    if(root->lchild != NULL){
        postorder(root->lchild);
    }
    if(root->rchild != NULL){
        postorder(root->rchild);
    }
    cout << root->data;
}

int main(){
    
    string preorder, inorder;
    while(cin >> preorder >> inorder){
        postorder(buildTree(preorder, inorder, inorder.length()));
        cout << endl;
    }
    
    return 0;
}