#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool cmp(int &a, int &b){
    return a < b;
}
int main(){
    int n, d, r;
    while(cin >> n >> d >> r){
        if(n == 0 && d == 0 && r== 0)
            break;
        vector<int> m, e;
        int tm, te, ot = 0;
        for(int i = 0; i < n; i++){
            cin >> tm ;
            m.push_back(tm);
        }
        for(int i = 0; i < n; i++){
            cin >> te;
            e.push_back(te);
        }
        sort(e.begin(), e.end());
        sort(m.begin(), m.end(), cmp);
        for(int i = 0 ;i < n; i++)                              
            if(m[i] + e[i] > d)
                ot += (m[i] + e[i] - d) * r;
        cout << ot << endl;
    }
    return 0;
}