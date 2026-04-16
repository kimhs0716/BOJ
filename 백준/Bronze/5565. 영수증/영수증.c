#include <stdio.h>
int main() {
    int s, a;
    scanf("%d", &s);
    for(int i = 0; i < 9; i++){
        scanf("%d", &a);
        s -= a;
    }
    printf("%d", s);
    return 0;
}
