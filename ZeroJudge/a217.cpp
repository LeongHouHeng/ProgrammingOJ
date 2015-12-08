#include <iostream>
#include <string>
#include <ctype.h>

using namespace std;

int main(){
	string input;
	while(getline(cin, input)){
		int first = 0;	//0 == true; 1 == false
		for(int i = 0; i < input.size(); i++){
		
			if(input[i] == '.' || input[i] == '?' || input[i] == '!'){
				putchar(input[i]);
				first = 0;
				continue;
			}
			if(input[i] == 'i'){
				if((input[i+1]<'A'||'Z'<input[i+1])&&(input[i+1]<'a'||input[i+1]>'z')){
					if((input[i-1]<'A'||'Z'<input[i-1])&&(input[i-1]<'a'||input[i-1]>'z')){
						putchar(toupper(input[i]));
						first = 1;	
						continue;
						putchar(input[i]);
					}
				}
					

			}
			if(first == 0 && input[i] != ' ' && input[i] != ','){
				putchar(toupper(input[i]));
				first = 1;
				continue;
			}
				cout << input[i];	
				
		}
		
		cout << endl;	
	}

	return 0;
}