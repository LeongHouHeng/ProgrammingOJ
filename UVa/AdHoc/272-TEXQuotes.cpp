#include <iostream>
#include <string>

using namespace std;
int main(){

	string str_input;
	string open = "``";
	string close = "\'\'";
	
	char check = '"';
	
	while(getline(cin, str_input)){
		string str_tmp;
		int count = 0;
		for(int i = 0; i <= str_input.length(); i++){
			if(str_input[i] == check){
				str_tmp[count] = str_input[i];
				if(count % 2 == 0){
					str_input.replace(i, 1, open);
				}else{
					str_input.replace(i, 1, close);
				}
				count ++;
			}
		}		
		cout << str_input;

	}
	
	return 0;
}
