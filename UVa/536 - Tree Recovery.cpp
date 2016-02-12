#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Node{
    public:
        char data;
        Node *lchild, *rchild;
        Node(char _data){
            data = _data;
            lchild = NULL;
            rchild = NULL;
        }
        ~Node(){
            if(lchild != NULL){
                delete lchild;
            }
            if(rchild != NULL){
                delete rchild;
            }
        }
        void postorder(){
            if(lchild != NULL){
                lchild->postorder();
            }
            if(rchild != NULL){
                rchild->postorder(); 
            }
            cout << data;
        }
        Node* rebuild(const string &pre, const string &in, int length){
            Node *current_node = new Node(pre[0]);
            int pos = in.find(pre[0]);
            if(pos > 0){
                current_node->lchild = rebuild(pre.substr(1, pos), in.substr(0, pos), pos);
            }
            if(length-1-pos > 0){
                current_node->rchild = rebuild(pre.substr(pos+1), in.substr(pos+1), length-1-pos);
            }
            return current_node;
        }
    
};
class Tree{
    public:
    	   Node *root;
           Tree(){
               root = NULL;
           } 
           ~Tree(){
               if(root != NULL){
                   delete root;
               }
           }
           Tree(const string &pre, const string &in, int lenghth){
               root = root->rebuild(pre, in, lenghth);
           }
           void postorder(){
               root->postorder();
           }
    
};

int main(){
    string preorder, inorder;    
    while(cin >> preorder >> inorder){
        Tree tree(preorder, inorder, inorder.length());
        tree.postorder();  
        cout << endl;  
        
    }
    
    return 0;
}