#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include <cctype>
using namespace std;

struct data{
    char name;
    int id;
    char strEnd;
};

bool cmp(data &a, data &b){
    return a.id < b.id;
}

int main(){
    int N;
    while(cin >> N){
        vector<data> datas;
        data dt;
        char cmpString = '/';
        bool succ = 1;
        while(N--){
            
            if(scanf("%d%c",&dt.id,&dt.strEnd)){
                dt.name = '+';
                datas.push_back(dt);
            }
            if(scanf("%c%d%c",&dt.name,&dt.id,&dt.strEnd)){
                if(cmpString == '/'){
                    cmpString = dt.name;
                }
                datas.push_back(dt);
            }
        }
            sort(datas.begin(), datas.end(), cmp);
            for(int i = 0; i < datas.size(); i++){
                if(datas[i].name != '+' || datas[i].name != cmpString){
                    succ = 0;
                }
            }
            
            if(succ == 1){
                for(int i = 0; i < datas.size(); i++){
                    if(datas[i].name == '+'){
                        cout << datas[i].id << datas[i].strEnd << endl;
                    }{
                        cout << datas[i].name << datas[i].id << datas[i].strEnd << endl;
                    }
                    
                }
            }else{
                cout << "fail" << endl;
            }
            
        //}
    }
  
    
    return 0;
}