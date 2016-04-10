#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

double sf = 2.23606797749978969;

ifstream fin("C-small-practice.in");
ofstream fout("C-small-practice.out");

double slove(double b, int n){
    if(n < 0){
        return 0;
    }
    if(n == 0){
        return 1;
    }
    return b * slove(b, n-1);
}

int main(){
    
    int n;
    //cin >> n;
    fin >> n;
    for(int i = 1; i <= n; i++){
        int input;
        //cin >> input;
        fin >> input;
        //cout << "Case #" << i << ": ";
        fout << "Case #" << i << ": ";        
        int ig = slove((sf+3), input);
        string str;
        stringstream ss;
        ss << ig;
        ss >> str;
        if(str.length() < str.length()-3){
            string result = "0";
            if(str.length() == 2){
                //cout << result+str << endl;
                fout << result + str;
            }
            if(str.length() == 1){
                result += "0";
                //cout << result+str << endl;
                fout << result + str;
            }
        }
        for(int j = str.length()-3; j < str.length(); j++){
            //cout << str[j];
            fout << str[j];
        }
        fout << endl;
        //if(i != n) fout << endl;
            //cout << endl;
    }
    
    return 0;
}