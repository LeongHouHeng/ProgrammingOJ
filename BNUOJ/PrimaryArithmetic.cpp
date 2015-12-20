#include <iostream>

using namespace std;

int main(){
	
	int x, y;

	while(cin >> x >> y){
		int n = 0;
		int p = 0;
		if(x == 0 && y == 0)
			break;
			
		while(x != 0 || y != 0){
			p = p + x%10 + y%10;
			x /= 10;
			y /= 10;
			p /= 10;
			
			if(p == 1)
				n++;
			
		}
		
		if(n == 0)
			cout << "No carry operation." << endl;
		else if(n == 1)
			cout << "1 carry operation." << endl;
		else
			cout << n << " carry operations." << endl;
	
	}
	
	return 0;
}
