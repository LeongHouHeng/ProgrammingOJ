#include <iostream>
#include <queue>

using namespace std;

struct Node{
    int self;
    Node *left;
    Node *right;
    Node(){left = NULL, right = NULL;};
};

int main(){
    
    queue<Node*> visited, unvisited;
    Node nodes[9];
    Node *current;
    
    unvisited.push(&nodes[0]);  //put root
    while(!unvisited.empty()){
        current = unvisited.front();
        if(current->left != NULL){
            unvisited.push(current->left);
        }
        if(current->right != NULL){
            unvisited.push(current->right);
        }
        
        visited.push(current);
        cout << current->self << endl;
        unvisited.pop();
    }
    
    return 0;
}
