#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int a = 0,b = 1;
string av, bv;
string beads;
int lenBeads;

int main(){
    vector<int> counts;
    
    ifstream fin("beads.in");
    ofstream fout("beads.out");
    
    fin >> lenBeads;
    fin >> beads;
    
    //如果係二分呢？
    
}