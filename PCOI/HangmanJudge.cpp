/*#include <iostream>
#include <string.h>
#include "memory.h"
#include <stdio.h>
#include <map>
#include <set>

using namespace std;

set<char> ans;
set<char> guess;
map<char, int> state;

int main(){

    char c;
    while((c = getchar())!= '\n'){
       
        ans.insert(c);
        state[c] = 1;
    }
    
    int lose = 0;
    int ansSize = (int)ans.size();
    
    char str[105];
    memset(str, 0, sizeof(str));
    scanf("%s", str);
    bool chicken = true;
    
    for(int i = 0; i < strlen(str); i++){
        c = str[i];
        if(state.find(c) != state.end()){
            if(state[c] == 1){
                guess.insert(c);
            }
        }else{
            lose++;
            state[c] = 2;
        }
        
        if(lose == 7){
            puts("You lose.");
            chicken = false;
            break;
        }
        
        int guessSize = (int)guess.size();
        if(guessSize == ansSize){
            puts("You win.");
            chicken = false;
            break;
        }
        
    }
    
    if(chicken){
        puts("You chickened out.");
    }
    
    return 0;
}
*/
/*http://www.cppblog.com/rakerichard/archive/2011/04/07/143606.html 大牛啊*/
#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <cstring>

using namespace std;
const int kMax(107);

int main(){
        string ans,guess;
        cin>>ans>>guess;

        bool hash_ans[kMax],hash_guess[kMax],hash_guessed[kMax];
        fill_n(hash_ans,kMax,false);
        fill_n(hash_guess,kMax,false);
        fill_n(hash_guessed,kMax,false);

        for(int i=0;i<ans.size();i++)
            hash_ans[ans[i]-'A']=true;
        int wrong(0);
        for(int i=0;i<guess.size();i++){
            if(hash_guessed[guess[i]-'A'])
                continue;
            hash_guessed[guess[i]-'A']=true;
            if(hash_ans[guess[i]-'A']){
                hash_guess[guess[i]-'A']=true;
                if(memcmp(hash_ans,hash_guess,kMax*sizeof(bool))==0)
                    break;
            }
            else
            {
                wrong++;
                if(wrong>=7)
                    break;
            }
        }

        if(wrong>=7)
            cout<<"You lose."<<endl;
        else if(memcmp(hash_ans,hash_guess,kMax*sizeof(bool))==0)
            cout<<"You win."<<endl;
        else cout<<"You chickened out."<<endl;
    

    return 0;
}