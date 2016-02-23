#include <iostream>
#include <string>
#include <vector>
using namespace std;

void preorder(char &root, vector<char> &left, vector<char> &right){
    int i;
    cout << root << " ";
    
    for(i = 0; i < left.size(); i++){
        if(left[i] != ' ')
            cout << left[i] << " ";
    }
    cout << endl;
    cout << i-1 << endl;
    cout << "--" << right[i-1] << endl;
        
}


int main(){
    vector<char> left;
    vector<char> right;
    char root;
    
    string input;
    getline(cin, input);
    
    /*int i = 0;
    root = input[i];
    left.push_back(input[i+1]);
    
    while(i*2+1 < input.length()){
        i++;
        int pi = 2*i;
        right.push_back(input[pi]);
        pi = 2*i+1;
        left.push_back(input[pi]);
    }
    
    for(int i = 0; i < right.size(); i++){
        cout << i << "= " << right[i] << endl;
    }
    
    cout << "Pre  : ";
    preorder(root, left, right);
    cout << endl;
    */
    vector<char> later;
    int i = 0;
    root = input[i];
    cout << root << " ";
    while(i*2 < input.length()){
        i++;
        int pi = 2*i;
        if(input[pi] != ' ')
            later.push_back(input[pi]);

        if(input[pi-1]!=' '){
            cout << input[pi-1] << " ";
            
        }
    }
    
    for(int i = 0; i < later.size(); i++){
        cout << later[i] << " "; 
    }
    
    //int i = 0;
    /*i = i-2;
    int tmp = i;
    while(i * 2 + 1 < input.length()){
        int pi = 2*i+1;
        if(input[pi] == root){
            cout << input[tmp-1] << " ";
        }else if(input[pi-1]!=' ')
            cout << input[pi-1] << " ";
        
        i--;
    }*/
    
    return 0;
}