#include <iostream>
#include <vector>

using namespace std;

int binary_search(vector<int> &data, int m, int left, int right){
	//int left = data.front();
	//int right = data.back();
	int mid;
	while(left < right){
		mid = (left + right) / 2;
		if(m > data[mid]){
			left = mid + 1;
		}else if(m < data[mid]){
			right = mid - 1;
		}else{
			return mid;
		}
	}


	return min(left, right);
	
}

int binary_search2(vector<int> data, int request){
	int left = data.front();
	int right = data.back();
	int mid;

	while(left < right){
		mid = (left + right) / 2;
		if(request == data[mid]) 
			return mid;
		if(request < data[mid])
			right = mid - 1;
		else
			left = mid + 1;
	}
	return min(left, right);
}

int main(){
	int n, m;
	while(cin >> n >> m){
		vector<int> nums;
		int num;
		for(int i = 0; i < n; i++){
			cin >> num;
			nums.push_back(num);
		}

		int ms;
		for(int i = 0; i < m; i++){
			cin >> ms;
			//cout << binary_search(nums, ms, nums.front(), nums.back()) << endl;
			cout << binary_search2(nums, ms) << endl;
		}

	}
}