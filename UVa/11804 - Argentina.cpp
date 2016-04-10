#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

struct teammeat{
    string name;
    int attack;
    int defend;
    
};

bool cmp(const teammeat &a, const teammeat &b){
    if(a.attack == b.attack){
        if(a.defend == b.defend){
            return a.name < b.name;
        }else{
            return a.defend < b.defend;
        }
    }else{
        return a.attack > b.attack;
    }
}

int main(){
    int t;
    while(cin >> t){
        int round = 0;
        while(t--){
            round++;
            vector<teammeat> teammeats;
            teammeat tmp;
            for(int i = 0; i < 10; i++){
                cin >> tmp.name >> tmp.attack >> tmp.defend;
                teammeats.push_back(tmp);
            }
            vector<string> att, def;
            sort(teammeats.begin(), teammeats.end(), cmp);
            for(int i = 0; i < 5; i++){
                att.push_back(teammeats[i].name);
            }
            for(int i = 5; i < 10; i++){
                def.push_back(teammeats[i].name);
            }
           
            sort(att.begin(), att.end());
            sort(def.begin(), def.end());
            cout << "Case " << round << ":" << endl;
            
            cout << "(";
            for(int i = 0; i < att.size()-1; i++){
                cout << att[i] << ", ";
            }
            cout << att[att.size()-1] << ")" << endl;
           
            cout << "(";
            for(int i = 0; i < def.size()-1; i++){
                cout << def[i] << ", ";
            }
            cout << def[def.size()-1] << ")" << endl;
            
        }
    }
    
    return 0;
}