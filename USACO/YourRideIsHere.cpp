#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int getNum(char c){
    return c - 'A' + 1;
}

int main(){
	ofstream fout("ride.out");
	ifstream fin("ride.in");
	string c1, c2;
    fin >> c1 >> c2;
    int c1m = 1, c2m = 1;
    for(int i = 0; i < c1.length(); i++){
        c1m *= getNum(c1[i]);
    }
    for(int i = 0; i < c2.length(); i++){
        c2m *= getNum(c2[i]);
    }
    
    if(c1m%47 == c2m%47){
        fout << "GO" << endl;
    }else{
        fout << "STAY" << endl;
    }
    
	
	return 0;
}