/* Problem here: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=36 */

#include <iostream>

using namespace std;

int main(){

	int i, j, max, cycle, pp;
	while(cin >> i >> j){
		if(j < i){
			int tmp = i;
			i = j;
			j = tmp;
		}		

		max = 0;
		
		for(int p = i; p <= j; p++){
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
		cout << i << " " << j << " " << max << endl;

	}
	return 0;
}

