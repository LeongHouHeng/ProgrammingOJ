#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#define MAX 22

using namespace std;

char line[MAX];
long long per[MAX];

int cmp(const void *a, const void *b){
	return *(char*)a - *(char*)b;
}

void swap(char *x, char *y){
	char w;
	w = *x;
	*x = *y;
	*y = w;
}

void permute(char *line, long long target, int len){
	qsort(line, len, sizeof(char), cmp);
	long long d, i;
	if(target == 0)
		return;

	for(d = 0, i = 0; i <= len && per[len-1]*i <= target; i++){
		d = per[len-1]*i;
	}
	swap(line, line+i-1);
	permute(line+1, target-d, len-1);
}

int main(){
	int c, cases, lvl;
	long long n, i;
    for(per[0]= 1, i = 1; i < MAX; i++){
		per[i] = per[i-1]*i;
	}
	cin >> cases;
	for (c = 0; c < cases; c++){
		cin >> line >> n;
		lvl = strlen(line);
		permute(line, n, lvl);
		cout << line << endl;
	}
	return 0;

}
