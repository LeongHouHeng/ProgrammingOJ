#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    
    int n, m;
    while(cin >> n >> m){
        if(n == 0 && m == 0)
            break;
            
        vector<int> d, k;
        int tmp;
        for(int i = 0; i < n; i++){
            cin >> tmp;
            d.push_back(tmp);
        }
        
        for(int i = 0; i < m; i++){
            cin >> tmp;
            k.push_back(tmp);
        }
        
        sort(d.begin(), d.end());
        sort(k.begin(), k.end());
        
        int sum = 0;
        for(int i = 0; i < k.size(); i++){
            for(int j = 0; j < d.size(); j++){
                if(k[i] >= d[j]){
                    sum += k[i];
                    d.erase(d.begin()+j);
                    break;
                }
            }
        }
        if(d.size() > 0)
            cout << "Loowater is doomed!" << endl;
        else
            cout << sum << endl;
    }
    
    return 0;
}