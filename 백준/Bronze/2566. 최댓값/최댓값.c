#include <stdio.h>
int main() {
    int a, x, y, m = -1;
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            scanf("%d", &a);
            if(m < a){
                m = a;
                y = i + 1;
                x = j + 1;
            }
        }
    }
    printf("%d\n%d %d", m, y, x);
    return 0;
}
