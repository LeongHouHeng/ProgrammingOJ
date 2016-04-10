#include <iostream>
#include <vector>
#include "memory.h"
using namespace std;

int train[2000];
int len[2000];
int len2[2000];
int tn;

int main(){
    int t;
    while(cin >> t){
        while(t--){
            cin >> tn;
            for(int i = tn-1; i >= 0; i--){
                len[i] = 1;
                len2[i] = 1;
                int tmp;
                cin >> tmp;
                train[i] = tmp;
            }
            for(int i = 0; i < tn; i++){
                for(int j = i+1; j < tn; j++){
                    if(train[i] < train[j]){
                        len[j] = max(len[j], len[i]+1);
                    }
                    if(train[i] > train[j]){
                        len2[j] = max(len2[j], len2[i]+1);
                    }
                }
            }
            int result = 0;
            for(int i = 0; i < tn; i++){
                result = max(result, len[i]+len2[i]-1);
            }
            cout << result << endl;
        }
    }
    
    return 0;
}