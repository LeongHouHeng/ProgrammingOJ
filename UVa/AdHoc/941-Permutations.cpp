#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
using namespace std;

int main(){
   
    long long fac[20];
    fac[0] = 1;
    fac[1] = 1;
    for(int i = 2; i < 20; i++){
        fac[i] = fac[i-1] * i;
    }
    int number;
    cin >> number;
    while(number--){
        char S[21]; //20 + 1
        long long N;
        cin >> S;
        cin >> N;
        sort(S, S+strlen(S));
        vector<char> s(S, S+strlen(S) ), t;
        for(int i = strlen(S) - 1; i; i--){
            int j = N / fac[i];
            t.push_back(s[j]);
            s.erase(s.begin()+j);
            N %= fac[i];
        }
        t.push_back(s[0]);
        t.push_back('\0');
        cout << &t[0] << endl;
    }
    
    return 0;
}
