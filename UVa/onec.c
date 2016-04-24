#include <stdio.h>
#include <stdlib.h>
int cmp(const void *a, const void *b){
    return (*(int*)a - *(int*)b);
}
int cmp2(const void *a, const void *b){
    return (*(int*)b - *(int*)a);
}
int main(){
    int n, d, r;
    while(~scanf("%d %d %d", &n, &d, &r)){
        if(n == 0 && d == 0 && r== 0)
            break;
        int m[n], e[n];
        int tm, te, ot = 0;
        for(int i = 0; i < n; i++){
            scanf("%d", &tm);
            m[i] = tm;
        }
        for(int i = 0; i < n; i++){
            scanf("%d", &te);
            e[i] = te;
        }
        qsort(e, n, sizeof(int), cmp);
        qsort(m, n, sizeof(int), cmp2);
        for(int i = 0 ;i < n; i++)                              
            if(m[i] + e[i] > d)
                ot += (m[i] + e[i] - d) * r;
        printf("%d\n", ot);
    }
    return 0;
}