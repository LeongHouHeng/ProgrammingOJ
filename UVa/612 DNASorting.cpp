#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

struct dna{
    string str_data;
    int sort;
    int id;
    
};

int checkSort(string str){
    int count = 0;
    for(int i = 0; i < str.length(); i++){
        for(int j = i; j < str.length(); j++){
            if(str[i] > str[j]){
                count++;
            }
        }
    }
    return count; 
}

bool cmp(dna &a, dna &b){
    if(a.sort == b.sort)
        return a.id < b.id;
    return a.sort < b.sort;
}

int main(){
    int M;
    string p;
    
    while(cin >> M){
        while(M--){
            getline(cin, p);            
            int n, m;
            cin >> n >> m;
            vector<dna> dnas;
            dna da; 
            string datas;
            for(int i = 0; i < m; i++){
                da.id = i;
                cin >> datas;
                da.str_data = datas;
                
                da.sort = checkSort(da.str_data);
                dnas.push_back(da); 
            }
            sort(dnas.begin(), dnas.end(), cmp);
            for(int i = 0; i <= dnas.size()-1; i++){
                cout << dnas[i].str_data << endl;
                
            }
            if(M > 0){
                cout << endl;
            }
            
        }
    }
    
    return 0;
}