#include <stdio.h>
int main() {
    char mbti[4];
    scanf("%s", mbti);
    printf((mbti[0] == 'E') ? "I" : "E");
    printf((mbti[1] == 'S') ? "N" : "S");
    printf((mbti[2] == 'T') ? "F" : "T");
    printf((mbti[3] == 'J') ? "P" : "J");
    return 0;
}
