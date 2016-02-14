#include <iostream>
#include <string>
#include <stack>
#include <queue>
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

void dfs(Node* root){
    if(root == NULL){
        return;
    }
    cout << root->data;
    dfs(root->lchild);
    dfs(root->rchild);
}

void bfs(Node* root){
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node* current_node = q.front();
        q.pop();
        if(current_node->lchild){
            q.push(current_node->lchild);
        }
        if(current_node->rchild){
            q.push(current_node->rchild);
        }
        cout << current_node->data;
    }
}

int main(){
    string pre_str, in_str;
    ans = "";
    cin >> pre_str;
    cin >> in_str;
    
    //cout << "dfs: " << endl;
    //dfs(Tree(pre_str, in_str, in_str.length()));
    //postorder(Tree(pre_str, in_str, in_str.length()));
    //cout << endl;
    //mirror(Tree(pre_str, in_str, in_str.length()));
    cout << endl;
    cout << "bfs: " << endl;
    bfs(Tree(pre_str, in_str, in_str.length()));
    cout << endl;
    return 0;
}