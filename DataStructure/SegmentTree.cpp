#include <iostream>
#include <vector>

using namespace std;

struct tree{
	int left;
	int right;
	int data;
};

int main(){
	
	vector<tree> trees;
	struct tree t;
	for(int i = 0; i < 10; i++){
		t.left = 2*i;
		t.right = 2*i+1;
		t.data = i;
		
		trees.push_back(t);
	}
	
	int input_l, input_r;
	while(cin >> input_l >> input_r){
		
		
	}
	
	return 0;
}