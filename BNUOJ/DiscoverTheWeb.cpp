#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

int main(){
	
	int t;
	while(cin >> t){
		while(t--){
			printf("Case %d:\n", t+1);
			string input, url;
			vector<string> records;
			int pointer = 0;
			int lastPointer = -1;
			records.push_back("http://www.lightoj.com/");
			while(cin >> input){
				if(input == "VISIT"){
					cin >> url;
					records.push_back(url);
					if(lastPointer == -1 && pointer != 0){
						lastPointer = pointer;
					}
					pointer = records.size()-1;
					printf("%s\n", records[pointer].c_str());
				}else if(input == "BACK"){
					if(lastPointer != -1 && (pointer-1) == lastPointer){
						pointer = lastPointer;	
						lastPointer = -1;		
					}else{
						pointer--;						
					}
					if(pointer < 0){
						pointer++;
						printf("Ignored\n");
					}else{
						//records.push_back(records[pointer]);
						printf("%s\n", records[pointer].c_str());
					}
				}else if(input == "FORWARD"){
					if(lastPointer != -1 && (pointer+1 ) == lastPointer){
						pointer = lastPointer;
						lastPointer = -1;
					}else{
						pointer++;					
					}
					if(pointer >= records.size()){
						pointer--;
						printf("Ignored\n");
					}else{
						//records.push_back(records[pointer]);
						printf("%s\n", records[pointer].c_str());
					}
				}else if(input == "QUIT"){
					break;
				}
			}	
			
		}
		
	}
	
	return 0;
}