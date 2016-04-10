#include <iostream>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
using namespace std;

int main(){
    ifstream fin("A-large-practice.in");    //ifstream fin("A-small-practice.in");
    ofstream fout("A-large-practice.out");  //ofstream fout("A-small-practice.out");
    int n;
    fin >> n;
    for(int cnt = 1; cnt <= n; cnt++){        
        int bg;
        fin >> bg;
        int len;
        fin >> len;
        vector<int> nums;
        for(int i = 0; i < len; i++){
            int tmp;
            fin >> tmp;
            nums.push_back(tmp);
        }
        int ansX, ansY;
        
        for(int i = len-1; i >= 0; i--){
            for(int j = 0; j < len; j++){
                if(i != j && nums[i] < bg && nums[j] < bg){
                    if(nums[i] + nums[j] == bg){
                        ansX = i;
                        ansY = j;
                    }
                }
            }
        }
        if(ansX > ansY){
            int tmp = ansX;
            ansX = ansY;
            ansY = tmp;
        }
        fout << "Case #" << cnt << ": ";
        fout << ansX+1 << " " << ansY+1 << endl;
        
    }
    
    return 0;
}