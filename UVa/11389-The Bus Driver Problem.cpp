#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp1(int &a, int &b){
    return a < b;
}
bool cmp2(int &a, int &b){
    return a > b;
}

int main(){
    
    int n, d, r;
    while(cin >> n >> d >> r){
        if(n == 0 && d == 0 && r== 0)
            break;
        
        vector<int> m, e;
        for(int i = 0; i < n; i++){
            int tm;
            cin >> tm ;
            m.push_back(tm);
        }
        for(int i = 0; i < n; i++){
            int te;
            cin >> te;
            e.push_back(te);
        }
        sort(m.begin(), m.end(), cmp1);
        sort(e.begin(), e.end(), cmp2);
        int ot = 0;
        for(int i = 0 ;i < n; ++i){
            int men = m[i] + e[i];
            if(men > d){
                ot += (men-d) * r;
            }
        }
        cout << ot << endl;
    }
    
    return 0;
}
