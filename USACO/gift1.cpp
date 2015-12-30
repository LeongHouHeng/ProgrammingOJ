/*
ID: LeongHouHeng
PROG: gift1
LANG: C++
 */
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

struct gift{
    string name;
    int gets_money;
    int give_money;
    
};

int main(){
    ifstream fin("gift1.in");
    ofstream fout("gift1.out");
    
    gift g;
    vector<gift> gifts;
    
    int np;
    string tmp_name;
    fin >> np;
    
    for(int i = 0; i < np; i++){
        fin >> tmp_name;
        g.name = tmp_name;
        g.gets_money = 0;
        g.give_money = 0;
        gifts.push_back(g);
    }
    
    int tmp_giveTotal = 0, tmp_give = 0;
    int tmp_giveMoney = 0;
    string tmp_gifname;
  
    for(int i = 0; i < np; i++){
        fin >> tmp_name;
    
        for(int j = 0; j < gifts.size(); j++){
    
            if(tmp_name == gifts[j].name){
                fin >> tmp_give >> tmp_giveTotal;
                
                if(tmp_giveTotal > 0){
                
                    tmp_giveMoney = tmp_give / tmp_giveTotal;
                    gifts[j].give_money += (tmp_giveMoney*tmp_giveTotal);
                   
                    for(int k = 0; k < tmp_giveTotal; k++){
                        fin >> tmp_gifname;
                   
                        for(int l = 0; l < gifts.size(); l++){
                            if(tmp_gifname == gifts[l].name){
                                gifts[l].gets_money += tmp_giveMoney;
                                
                            }
                        }
                    }
                
                }
            }
        }
    }
    
    int result = 0;
    for(int i = 0; i < np; i++){
        result = gifts[i].gets_money - gifts[i].give_money;
        fout << gifts[i].name << " " << result << endl; 
    }
    
    
    return 0;
}