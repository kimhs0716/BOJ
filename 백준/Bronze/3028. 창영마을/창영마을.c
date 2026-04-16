#include <stdio.h>
int main() {
    char str[51];
    int ball = 0;
    scanf("%s", str);
    int i = 0;
    while (str[i]) {
        if (str[i] == 'A') {
            if (ball == 0) ball = 1;
            else if (ball == 1) ball = 0;
        }
        if (str[i] == 'B') {
            if (ball == 1) ball = 2;
            else if (ball == 2) ball = 1;
        }
        if (str[i] == 'C') {
            if (ball == 0) ball = 2;
            else if (ball == 2) ball = 0;
        }
        i++;
    }
    printf("%d", ball + 1);
    return 0;
}
