#include <iostream>
#include <vector>

using namespace std;

void swap(int *a, int *b){
	int *tmp = a;
	a = b;
	b = a;
}

int main(){

	int n;

	while(cin >> n){
		int flag = 0;	//0 => Marcelo	1=> Carlos

		if(n == 0)
			break;

		int input;
		vector<int> inputs;
		while(n--){
			cin >> input;
			inputs.push_back(input);
		}

		for(int j = 0; j < inputs.size(); j++){
			for(int i = 1; i < j; i++){
				
				if(inputs[i-1] > inputs[i]){
					if(flag == 1)
						flag = 0;
					else
						flag = 1;
					swap(inputs[i-1], inputs[i]);
				}

			}
		}

		if(flag == 1){
			cout << "Carlos" << endl;
		}else{
			cout << "Marcelo" << endl;
		}

	}


	return 0;
}