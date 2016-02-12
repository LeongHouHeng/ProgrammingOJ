#include <iostream>
#include <string>
#include <stack>
using namespace std;
string ans;
struct Node{
    char data;
    Node* lchild;
    Node* rchild;
};
Node* Tree(const string &pre, const string &in, int length){
    Node* current_node = new Node();
    current_node->data = pre[0];
    int pos = in.find(pre[0]);
    if(pos > 0){
        current_node->lchild = Tree(pre.substr(1, pos), in.substr(0, pos), pos);
    }
    if(length-1-pos){
        current_node->rchild = Tree(pre.substr(pos+1), in.substr(pos+1), length-1-pos);
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
    //ans += root->data;
}

void mirror(Node* root){
    if(root->rchild != NULL){
        mirror(root->rchild);
    }
    if(root->lchild != NULL){
        mirror(root->lchild);
    }
    cout << root->data;
}

int main(){
    string pre_str, in_str;
    ans = "";
    cin >> pre_str;
    cin >> in_str;
 
    postorder(Tree(pre_str, in_str, in_str.length()));
    cout << endl;
    mirror(Tree(pre_str, in_str, in_str.length()));
    cout << endl;
    return 0;
}