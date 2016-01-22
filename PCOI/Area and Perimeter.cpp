#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

int main(){
    
    float a, b, c, s;
    scanf("%f%f%f", &a,&b,&c);
    s = (a+b+c)/2;
        
    printf("Right Angled Triangle\n");
    printf("---------------------\n");
    printf("Area %16.2lf\n", sqrt(s*(s-a)*(s-b)*(s-c)));
    printf("Perimeter %11.2lf\n", a+b+c);
        
    return 0;
}