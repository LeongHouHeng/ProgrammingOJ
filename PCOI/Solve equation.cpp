#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include <vector>
#include <ctype.h>
#include <iomanip>

using namespace std;

void SplitString(const string& s, vector<string>& v, const string& c){
  string::size_type pos1, pos2;
  pos2 = s.find(c);
  pos1 = 0;
  while(std::string::npos != pos2){
    v.push_back(s.substr(pos1, pos2-pos1));
 
    pos1 = pos2 + c.size();
    pos2 = s.find(c, pos1);
  }
  if(pos1 != s.length())
    v.push_back(s.substr(pos1));
}

int main(){
    
    string input;
    cin >> input;
    
    stringstream ss;
    float a, b, c, x;
    
    vector<string> Ploy;
    SplitString(input, Ploy, "=");
    ss << Ploy[1];
    ss >> c;
    
    string computeStr = Ploy[0];
    vector<string> compute;
    SplitString(computeStr, compute, "+");
    
    string aStr = "", bStr = "";
    char unknowNum;
    bool XIsInA = false;
    for(int i = 0; i < compute[0].length(); i++){
        if(isdigit(compute[0][i]) || compute[0][i] == '.'){
            aStr += compute[0][i];
        }else{
            unknowNum = compute[0][i];
            XIsInA = true;
        }
    }
    
    ss.clear();
    ss << aStr;
    ss >> a;
    
    for(int i = 0; i < compute[1].length(); i++){
        if(isdigit(compute[1][i]) || compute[1][i] == '.'){
            bStr += compute[1][i];
        }else{
            unknowNum = compute[1][i];
        }
    }
    
    ss.clear();
    ss << bStr;
    ss >> b;
    
    /*
      ax + b = c; or a + bx = c;
      ax = c-b;   or bx = c-a;
      x = (c-b)/a or x = (c-a)/b;
      
      */
      
    if(XIsInA){ //ax+b=c
        cout << unknowNum << "=";
        //if(aI != 0)
        cout << fixed << setprecision(2) << (c-b)/a << endl;
            
    }else if(!XIsInA){
        cout << unknowNum << "=";
        //if(bI != 0)
        cout << fixed << setprecision(2) << (c-a)/b << endl;
    }
    
    return 0;
}