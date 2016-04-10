#include <iostream>
#include <stack>
#include <vector>
#include <fstream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

struct word{
    string w;
};

ofstream fout("B-large-practice.out");
//ofstream fout("B-small-practice.out");
//ifstream fin("B-small-practice.in");
ifstream fin("B-large-practice.in");

int main(){
    int n;
    fin >> n;
    fin.ignore();
    for(int cnt = 1; cnt <= n; cnt++){
        string input;
        getline(fin, input);
        vector<word>words;
        int start = 0;
        
        for(int i = 0 ; i <= input.length(); i++){
            if(i == input.length()){
                string tmp = "";
                word wtmp;
                for(int j = start; j < i; j++){
                    tmp+= input[j];
                }
                wtmp.w = tmp;
                words.push_back(wtmp);
                start = i+1;
            }        
            if(input[i] == ' '){
                string tmp = "";
                word wtmp;
                for(int j = start; j < i; j++){
                    tmp += input[j];
                }
                wtmp.w = tmp;
                words.push_back(wtmp);
                start = i+1;
            }
        }
        
        stack<word> ws;
        for(int i = 0; i < words.size(); i++){
            ws.push(words[i]);
        }
        int count = 0;
        fout << "Case #" << cnt << ": ";
        while(!ws.empty()){
            if(count != 0){
                fout << " " << ws.top().w;                
            }else{
                fout << ws.top().w;            
            }
            ws.pop();
            count++;
        }
        fout << endl;
    }
    
    return 0;
}