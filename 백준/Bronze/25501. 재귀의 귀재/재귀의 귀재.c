#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int count;  // recursion 함수 호출 횟수

int recursion(const char* s, int l, int r) {
    count++;
    if (l >= r) return 1;
    else if (s[l] != s[r]) return 0;
    else return recursion(s, l + 1, r - 1);
    
}

int isPalindrome(const char* s) {
    return recursion(s, 0, strlen(s) - 1);
}

int main() {
    int t;
    scanf("%d", &t);    // 테스트 케이스의 개수

    char str[1001];
    for (int i = 0; i < t; i++) {
        count = 0;
        scanf("%s", str);
        
        int result = isPalindrome(str);
        printf("%d %d\n", result, count);
    }
    return 0;
}