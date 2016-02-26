#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
using namespace std;
vector<int>books;
int book;
int money;
int ansI, ansJ;
void slove(int l, int r){
    int dis = 9999999;
    for(int i = 0; i < books.size(); i++){
        for(int j = 0; j < books.size(); j++){
            if(books[i] + books[j] == money && books[i] != money && books[j] != money){
                int tmp = (books[i] < books[j]) ? (books[j] - books[i]) : (books[i] - books[j]);
                if(tmp < dis){
                    dis = tmp;
                    ansI = i;
                    ansJ = j;
                }
            }
        }
    }
}

int main(){
    
    int n;
    while(cin >> n){
        for(int i = 0; i < n; i++){
            cin >> book;
            books.push_back(book);
        }
        cin >> money;
        sort(books.begin(), books.end());
        slove(0, books.size()-1);
        cout << "Peter should buy books whose prices are " << books[ansI] << " and "<< books[ansJ] << "." << endl;
        cout << endl;
        char c = getchar();
        books.clear();
        ansI = 0;
        ansJ = 0;
    }
    
    return 0;
}
