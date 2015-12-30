#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int a = 0,b = 1;
string av, bv;
string beads;
int lenBeads;

int main(){
    vector<int> counts;
    
    ifstream fin("beads.in");
    ofstream fout("beads.out");
    
    fin >> lenBeads;
    fin >> beads;
    
    
    
    while(b < lenBeads){
        char ac, bc;
        int count = 0;
        for(int i = 0; i <= a; i++){
            av[i] = beads[i];
        }
        int j = 0;
        for(int i = b; i < lenBeads; i++){
            bv[j] = beads[i];
            j++;    
        }
        
        ac = av.back();
        bc = bv.front();
        
        for(int i = a; i > 0; i--){
            if(ac == av[a] || av[a] == 'w'){
                count ++;
            }
        }
        for(int i = b; i < bv.length(); i++){
            if(bc == bv[b] || bv[b] == 'w'){
                count ++;
            }
        }
        
        counts.push_back(count);
        /*
        if(a > 0)
            a--;
        */
        a++;
        b++;
    }
    
    fout << *max_element(counts.begin(), counts.end());
    
}