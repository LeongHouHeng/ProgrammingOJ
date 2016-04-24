#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class Time{
    public:
        string whatTime(int seconds);
    
};

string Time::whatTime(int seconds){
    int h = seconds / 60 / 60;
    int m = seconds / 60 - h*60;
    int s = seconds - h*60*60 - m*60;
    char str[100];
    sprintf(str, "%d:%d:%d", h, m, s);
    string result = str;
    return result;
}

int main(){
    
    Time t;
    cout << t.whatTime(86399) << endl;
    
    return 0;
}