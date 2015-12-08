#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct arrays{
    int index;
    string data;
    
};


bool cmp(struct arrays a, struct arrays b){
    return a.index < b.index;
}

int main(){
    int nl;
    string blank;
    
    cin >> nl;
    getline(cin, blank);

    while(nl--){

        int input;
        int count = 0;
        struct arrays as;
        vector<struct arrays> ays;
        int a[1000];
        while(cin >> input){
            a[count] = input;
            count ++;
            if(cin.get()=='\n'){
                break;
            }
        }
        string input_number;
        int count2 = 0;
        while(cin >> input_number){
            as.data = input_number;
            as.index = a[count2];
            ays.push_back(as);
            count2++;

            if(cin.get()=='\n'){
                break;
            }
        }
        sort(ays.begin(), ays.end(), cmp);
        
        cout << endl;
        
        for(int i = 0; i < count; i++){
            cout << ays[i].data << endl;
        }
        cout << endl;
 
    }


    return 0;
}
