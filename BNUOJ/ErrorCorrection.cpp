#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

typedef vector<int> iVec;
typedef vector<iVec> vVec;	

string checks(vector<iVec> m){
	string result;

	int er_x, er_y;
	int pass_x, pass_y;
	
	for(int i = 0; i < m.size(); i++){
		int x, y;
		for(int j = 0; j < m.size(); j++){
			if(m[i][j] % 2)	x++;
			if(m[j][i] % 2) y++;
			
		}
		if(x % 2 != 0){
			pass_x ++;
			er_x  = i;			
		}
		if(y % 2 != 0){
			pass_y ++;
			er_y = i;
		}
		
	}
	
	if(pass_x == 0 && pass_y == 0){
		result = "OK";
	}else if(pass_x == 1 && pass_y == 1){
		
		stringstream ssx, ssy;
		string ex, ey;
		ssx << er_x;
		ssy << er_y;
		ssx >> ex;
		ssy >> ey;
		
		result = "Change bit (" + ex + "," + ey + ")";
	}else{
		result = "Corrupt";
	}
	return result;
	
}

int main(){
	
	int n;
	while(cin >> n){
		if(n == 0)
			break;
		
		vVec mixt;
		iVec datas;
		for(int i = 0; i < n; i++){
			datas.clear();
			int data;
			for(int j = 0; j < n; j++){
				cin >> data;
				datas.push_back(data);
			}
			mixt.push_back(datas);
			
		}
		//cout << mixt[1][1] << endl;
		cout << checks(mixt) << endl;
		
	}	
	
	return 0;
}