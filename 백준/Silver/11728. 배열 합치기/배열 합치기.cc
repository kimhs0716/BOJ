#include <stdio.h>
int main(){
    int la, lb;
    scanf("%d %d", &la, &lb);
    int a[la], b[lb];
    for(int i = 0; i < la; i++)
        scanf("%d", &a[i]);
    for(int i = 0; i < lb; i++)
        scanf("%d", &b[i]);
    int c[la + lb];
    for(int i = 0; i < la + lb; i++) c[i] = 0;
    int idx = 0, ia = 0, ib = 0;
    while(ia < la && ib < lb){
        if(a[ia] < b[ib]){
            c[idx++] = a[ia++];
        }
        else c[idx++] = b[ib++];
    }
    while(ia < la) c[idx++] = a[ia++];
    while(ib < lb) c[idx++] = b[ib++];
    for(int i = 0; i < la + lb; i++) printf("%d ", c[i]);
    return 0;
}
