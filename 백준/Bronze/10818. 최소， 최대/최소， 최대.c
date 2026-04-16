#define _CRT_SECURE_NO_WARNINGS //비주얼 스튜디오 사용자라면 필수!
#include <stdio.h>

// boj.kr/10818
int main(){
    int n, min = 1000000, max = -1000000, num;
    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        scanf("%d", &num);
        if(min > num) min = num;
        if(max < num) max = num;
    }

    printf("%d %d\n", min, max);

    return 0;
}
