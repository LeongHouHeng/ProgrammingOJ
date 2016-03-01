#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct dragon{
    int level;
    int bonus;
};
bool cmp(dragon &a, dragon &b){
    return a.level < b.level;
}

int main(){
    int s, n;
    while(cin >> s >> n){
        int bs = s;
        bool next = true;
        vector<dragon> vd;
        dragon d;
        while(n--){
            int l, b;
            cin >> l >> b;
            d.level = l;
            d.bonus = b;
            vd.push_back(d);
        }
        sort(vd.begin(), vd.end(), cmp);
        for(int i = 0; i < vd.size(); i++){
            if(bs > vd[i].level){
                bs += vd[i].bonus;
            }else{
                next = false;
            }
        }
        if(next){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }
    return 0;
}