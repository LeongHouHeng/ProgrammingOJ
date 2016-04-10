#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string input;

bool cmp( char A, char B ){
	bool isua = isupper( A );
	bool isub = isupper( B );

	if( isua ) A = A-'A'+'a';
	if( isub ) B = B-'A'+'a';

	if( (isua^isub) && A==B ) return isua;
	return A<B;
}
int main(){
    
    int n;
    while(cin >> n){
        while(n--){
            cin >> input;
            sort(input.begin(), input.end(), cmp);
            do{
                cout << input << endl;
            }while(next_permutation(input.begin(), input.end()));
        }
    }
    
    return 0;
}