#include <iostream>
#include <string>

using namespace std;
int main(){

	string str_input;
	char check = '"';
	int flag = 0; //0 is open, 1 is close
	while(getline(cin, str_input)){
        
		for(int i = 0; i < str_input.length(); i++){
            if(str_input[i] == check){
				
				if(flag == 0){
				    cout << "``";
                    flag = 1;
                }else{
				    cout << "''";
                    flag = 0;
                }
				
			}else{
                cout << str_input[i];   
            }
		}		
        cout << endl;
        
	}
	
	return 0;
}
