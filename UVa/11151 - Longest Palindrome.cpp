#include <iostream>
#include <string>
#include "memory.h"
#include <fstream>
using namespace std;
int dp[1000][1000];

ifstream fin("test.in");
ofstream fout("test.out");

int slove(string str, int i, int j){
    if(i == j)
        return 1;
    if(i > j)
        return 0;
    if(dp[i][j] != -1)
        return dp[i][j];
        
    if(str[i] == str[j])
        dp[i][j] = slove(str, i+1, j-1) + 2;
    else if(slove(str ,i+1, j) > slove(str, i, j-1))
        dp[i][j] = slove(str, i+1, j);
    else if(slove(str, i+1, j) < slove(str, i, j-1))
        dp[i][j] = slove(str, i, j-1);
    else
        dp[i][j] = slove(str, i, j-1);
    
    
    return dp[i][j];
}

int main(){
    int t;
    while(fin >> t){
        while(t--){
            string input;
            fin.ignore();
            getline(fin, input);
            memset(dp, -1, sizeof(dp));
            if(input.size() == 0)
                fout << 1 << endl;
            else
                fout << slove(input, 0, input.length()-1) << endl;
        }
    }
    
    return 0;
}