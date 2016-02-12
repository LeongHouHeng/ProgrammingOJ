/*
ID: LeongHouHeng
PROG: test
LANG: C++
 */
#include<fstream>
using namespace std;
 
int main()
{
    int num,max=0,n,i,j,k;
    char *p,symbol1,symbol2;
    ifstream fin("beads.in");
    ofstream fout("beads.out");
 
    fin>>n;
    p=new char[n+1];
    fin>>p;
 
    for(i=n;i<2*n;++i){
        if(p[i%n]!=p[(i+1)%n]){                               
            symbol1=p[i%n]!='w'?p[i%n]:(p[(i+1)%n]=='r'?'b':'r');   
            symbol2=symbol1=='r'?'b':'r';
            num=0;
 
            for(j=i;j>i-n;--j){
                if(p[j%n]==symbol1||p[j%n]=='w') ++num;        
                else break;
            }
            for(k=i+1;k<j+n+1;++k){
                if(p[k%n]==symbol2||p[k%n]=='w') ++num;
                else break;
            }
 
            max=max>num?max:num;                     
        }
    }
 
    if(max==0) max=n;                               
    fout<<max<<endl;
    fin.close();
    fout.close();
    delete [] p;
 
    return 0;
}