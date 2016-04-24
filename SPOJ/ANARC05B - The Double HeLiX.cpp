#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n;
    while(cin >> n){
        if(n == 0)
            break;
        
        vector<int> v1, v2;
        int v;
        for(int i = 0; i < n; i++){
            cin >> v;
            v1.push_back(v);
        }
        int n2;
        cin >> n2;
        for(int i = 0; i < n2; i++){
            cin >> v;
            v2.push_back(v);
        }
        vector<int> v1pos, v2pos;
        for(int i = 0; i < v1.size(); i++){
            for(int j = 0; j < v2.size(); j++){
                if(v1[i] == v2[j]){
                    v1pos.push_back(i);
                    v2pos.push_back(j);
                }
            }
        }
        int max = 0;
        int pos = v1pos[0];
        int pos2 = v2pos[0];
        int cnt1 = 0, cnt2 = 0;
        while(pos < v1pos[v1pos.size()-1] && pos2 < v2pos[v2pos.size()-1]){
            int sum = 0;
            for(int i = pos; i < v1pos[cnt1+1]; i++){
                sum += v1[v1pos[pos]];
            }
            int sum2 = 0;
            for(int i = pos2; i < v2pos[cnt2+1]; i++){
                sum2 += v2[v2pos[pos2]];
            }
            cnt1++;//cout << cnt1 << endl;
            cnt2++;
            pos = v1pos[cnt1];
            pos = v2pos[cnt2];
            max += (sum >= sum2) ? sum : sum2;
            //cout << cnt1 << " " << max << endl;
        }
        if(pos == v1pos[v1pos.size()-1] || pos2 == v2pos[v2pos.size()-1]){
            int sum = 0;
            for(int i = pos; i < v1.size(); i++){
                sum += v1[i];
            }
            int sum2 = 0;
            for(int i = pos2; i < v2.size(); i++){
                sum2 += v2[i];
            }
            max += (sum >= sum2) ? sum : sum2;
        }
        cout << max << endl;
    }
    
    return 0;
}