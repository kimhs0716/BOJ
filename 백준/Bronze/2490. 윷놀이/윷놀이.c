#include <stdio.h>
int main() {
    int a, s;
    char yoot[] = {'D', 'C', 'B', 'A', 'E'};
    for(int i = 0; i < 3; i++){
        s = 0;
        for(int j = 0; j < 4; j++){
            scanf("%d", &a);
            s += a;
        }
        printf("%c\n", yoot[s]);
    }
    return 0;
}
