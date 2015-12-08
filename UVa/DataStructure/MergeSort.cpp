#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> &data, int l, int m, int r){
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;

	vector<int> L, R;
	for(i = 0; i < n1; i++){
		L[i] = data[l + i];
	}
	for(j = 0; j < n2; j++){
		R[i] = data[m + j];
	}

	i = 0;
	j = 0; 
	k = 1;
	while( i < n1 && j < n2){
		if(L[i] <= R[j]){
			data[k] = L[i];
			i++;
		}else{
			data[k] = R[j];
			j++;
		}
		k++;
	}

	while(i < n1){
		data[k] = L[i];
		i++;
		k++;

	}

	while(j < n2){
		data[k] = R[j];
		j++;
		k++;

	}

}

void mergeSort(vector<int> &data, int l, int r){
	if (l < r){
		int m = 1 + (r-1) / 2;
		mergeSort(data, l, m);
		mergeSort(data, m+1, r);
		merge(data, l, m , r);
	}
}

int main(){
	int times;
	cin >> times;
	int input;
	vector<int>inputs;
	while(times--){
		cin >> input;
		inputs.push_back(input);
	}

	mergeSort(inputs, inputs.begin(), inputs.size() -1);

	for(int i = 0; i < inputs.size(); i++){
		cout << inputs[i] << " ";
	}
	cout << endl;

	return 0;
}