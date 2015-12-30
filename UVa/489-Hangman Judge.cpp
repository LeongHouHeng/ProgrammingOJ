#include <iostream>
#include <string.h>
#include <stdio.h>
#define maxn 100
using namespace std;

int lf, chance;
char s[maxn], s2[maxn];
int win, lose;

void guess(char ch){
    
    int bad = 1;
    for(int i = 0; i < strlen(s); i++)
        if(s[i] == ch){
            lf--;
            s[i] = ' ';
            bad = 0;
        }
        
        if(bad)
            --chance;
        if(!chance)
            lose = 1;
        if(!lf)
            win = 1;
    
}

int main(){
    int p;
    while(cin >> p){
        if(p == -1)
            break;
        cin >> s >> s2;
            
        cout << "Round " << p << endl;
        win = lose = 0;
        lf = strlen(s);
        chance = 7;
        for(int i = 0; i < strlen(s2); i++){
            guess(s2[i]);
            if(win||lose){
                break;
            }
        }
        
        if(win)
            cout << "You win." << endl;
        else if(lose)
            cout << "You lose." << endl;
        else
            cout << "You chickened out." << endl;
        
    }
    
    return 0;
}