#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

struct student{
    int id;
    string name;
    int termSource;
    int classSource;
    bool isMS;
    bool isWestStd;   
    int paperCnt;
    
    int money;
    int money2;
};

bool cmp(student &a, student &b){
    if(a.money == b.money){
        return a.id < b.id;
    }else{
        return a.money > b.money;
    }
}

int main(){
    int n;
    while(cin >> n){
        vector<student> students;
        for(int i = 0; i < n; i++){
            student stds;
            stds.id = i;
            cin >> stds.name >> stds.termSource >> stds.classSource;
            char state;
            cin >> state;
            if(state == 'Y'){
                stds.isMS = true;
            }else if(state == 'N'){
                stds.isMS = false;
            }
            cin >> state;
            if(state == 'Y'){
                stds.isWestStd = true;
            }else if(state == 'N'){
                stds.isWestStd = false;
            }
            cin >> stds.paperCnt;
            stds.money = 0;
            stds.money2 = 0;
            students.push_back(stds);
        }
        for(int i = 0; i < students.size(); i++){
            if(students[i].paperCnt >= 1 && students[i].termSource > 80){
                students[i].money += 8000;
            }
            if(students[i].termSource > 85 && students[i].classSource > 80){
                students[i].money += 4000;
            }
            if(students[i].termSource > 90){
                students[i].money2 += 2000;
                students[i].money += 2000;
            }
            if(students[i].isWestStd == true && students[i].termSource > 85){
                students[i].money += 1000;
            }
            if(students[i].isMS == true && students[i].classSource > 80){
                students[i].money2 += 850;
                students[i].money += 850;
            }
        }
        
        sort(students.begin(), students.end(), cmp);
        cout << students[0].name << endl;
        cout << students[0].money2 << endl;
        cout << students[0].money << endl;
        
        
    }
    return 0;
}
