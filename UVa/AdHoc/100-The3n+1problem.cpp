/* Problem here: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=36 */

#include <iostream>

using namespace std;

int main(){

    unsigned long int i, j, max, cycle, pp;
	while(cin >> i >> j){
        cout << i << " " << j ;
		if(i>j){
			unsigned long int tmp = i;
			i = j;
			j = tmp;
		}		

		max = 0;
		
		for(unsigned long int p = i; p <= j; p++){
			cycle = 1;
			pp = p;
			while(pp != 1){
				if(pp%2==0){
					pp = pp/2;
				}else{
					pp = 3*pp+1;
				}
				cycle = cycle + 1;
			}
		
			max = (max > cycle) ? max : cycle;
		}
		cout << " " << max << endl;

	}
	return 0;
}

