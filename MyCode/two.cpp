#include <iostream>
using namespace std;

void print_subset(int n, int s){
    for(int i = 0; i < n; i++){
        if(s&(1<<i))
            cout << i;
    }
    cout << endl;
}

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < (1<<n); i++){
        print_subset(0, i);
    }
    return 0;
}