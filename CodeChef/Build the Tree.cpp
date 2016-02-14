#include <iostream>
#include <list>
using namespace std;

struct Node{
    int cost;
    Node* lchild;
    Node* rchild;
    Node():cost(-1), lchild(NULL), rchild(NULL);
};
Node* buildTree(list<int> lt){
    Node* root = new Node();
    root->cost = lt.front();
    lt.pop_front();
    
}

int main(){
    
    return 0;
}