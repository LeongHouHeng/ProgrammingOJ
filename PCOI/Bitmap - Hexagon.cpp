#include <iostream>
using namespace std;

int main(){
    
    int n;
    cin >> n;
    int height = 2*n-1;
    int mid = height/2 + 1;
    int tmp = mid - 1;
    for(int i = 0; i < mid; i++){
        for(int j = 0; j < tmp; j++){
            cout << " ";
        }
        tmp--;
        if(i==0){
            cout << "****" << endl;
        }else{
            cout << "*";
        }
        cout << endl;
    }
    /*
       ****
      *    *
     *      *
    *        *  <- mid
     *      *
      *    *
       ****             //e.g. n = 4
       height: 2n-1;    //  7
       mid: (2n-1)/2 + 1//  4
       tmp = mid - 1;
       for i = 0 < mid; i ++
        for  j = 0; j < tmp; j++
            cout << " ";
        tmp--;
        if(i == 0)  cout << "****" << endl;
        else    cout << "*";
    */
    return 0;
}