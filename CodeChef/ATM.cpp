#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

int main(){
    double n, m;
    while(cin >> n >> m){
        double ans, c;
        if(n+0.5 <= m){
            c = fmod(n, 5);
            if(c == 0){
                ans = m - n - 0.5;
                cout << fixed << setprecision(2) << ans << endl;
            }else{
                cout << fixed << setprecision(2) << m << endl;
            }
        }else{
            cout << fixed << setprecision(2) << m << endl;
        }
    }
    
    return 0;
}