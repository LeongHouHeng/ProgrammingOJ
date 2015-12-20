#include <iostream>
#include <deque>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

int main(){
	
	int s;
	while(cin >> s){
		char lr, ad;
		int num = -1;
		deque<int> cows;
		int count = 0;
		while(s--){

			cin >> ad;
			if(ad == 'A'){
				count ++;
				cin >> lr;
				if(lr == 'L')
					cows.push_front(count);
				else if(lr == 'R')
					cows.push_back(count);
					
			}else if(ad == 'D'){
				cin >> lr >> num;
				if(lr == 'L'){
					for(int i = 0; i < num; i++){
						cows.pop_front();
					}
				}else if(lr == 'R'){
					for(int i = 0; i < num; i++){
						cows.pop_back();
					}
					
				}
			}
		}
		

		for(deque<int>::iterator alfa_it = cows.begin(); alfa_it != cows.end(); alfa_it++){
			printf("%d\n", *alfa_it);
		}
	
	}
	
	return 0;
}