#include <stdio.h>
void cake(int *a, int *b, int *c){
    c[0] = a[2] + b[0];
    c[1] = a[1] * b[1];
    c[2] = a[0] + b[2];
}
int main(){
    int a[3], b[3], c[3], d[3];
    for(int i = 0; i < 3; i++)
        scanf("%d", &a[i]);
    for(int i = 0; i < 3; i++)
        scanf("%d", &c[i]);
    for(int x = 1; x <= 100; x++){
        b[0] = x;
        for(int y = 1; y <= 100; y++){
            b[1] = y;
            for(int z = 1; z <= 100; z++){
                b[2] = z;
                cake(a, b, d);
                if(d[0] == c[0] && d[1] == c[1] && d[2] == c[2])
                    goto EXIT;
            }
        }
    }
EXIT:
    printf("%d %d %d\n", b[0], b[1], b[2]);
    return 0;
}
