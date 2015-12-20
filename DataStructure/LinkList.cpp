#include <iostream>

using namespace std;

class Node{
	public:
		int data;
		Node* next;
		Node(int _data){
			data = _data;
			next = NULL;
		}
	
};

class LinkList{
	private:
		Node *head;
	public:
		LinkList(){
			
			head = NULL;
		}

		void insert(Node *node, int index){	//index 是該元素在鏈表中的位置
			if(head == NULL){	//確定鏈表不為空
				head = node;
				return;
			}
			if(index == 0){		
				node->next = head;
				head = node;
				return;
			}
			Node *current_node = head;
			int count = 0;
			
			while(current_node->next != NULL && count < index - 1){
				current_node = current_node->next;
				count ++;
			}
			
			if(count == index - 1){
				node->next = current_node->next;
				current_node->next = node;
				
			}
		}
		
		void output(){
			if(head == NULL){
				return;
			}
			
			Node *current_node = head;
			while(current_node != NULL){
				cout << current_node->data << " ";
				current_node = current_node->next;
				
			}
			cout << endl;
			
		}
		
		void delete_node(int index){
			if(head == NULL){
				return;
				
			}
			
			Node *current_node = head;
			int count = 0;
			
			if(index == 0){
				head = head->next;
				delete current_node;
				return;
				
			}
			
			while(current_node->next != NULL && count < index - 1){
				current_node = current_node->next;
				count++;
			}
			
			if(count == index-1 && current_node->next != NULL){
				Node *delete_node = current_node->next;
				current_node->next = delete_node->next;
				delete delete_node;
			}
			
		}
		
		void reserve(){
			if(head == NULL){
				return;
			}
			Node *current_node, *next_node;
			current_node = head->next;
			head->next = NULL;
			
			while(current_node != NULL){
				next_node = current_node->next;
				current_node->next = head;
				head = current_node;
				current_node = next_node;
			}
			
		}
		
};

int main(){
	LinkList linklist;
	
	for(int i = 0; i < 10; i++){
		Node *node = new Node(i);
		linklist.insert(node, i);	
		
	}
	
	linklist.output();
	
	linklist.delete_node(5);
	linklist.output();
	
	linklist.reserve();
	linklist.output();
	
	return 0;
}