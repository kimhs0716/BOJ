#include<stdio.h>
int cache[101][101][101] = {0, };
int w(int a, int b, int c){
    if(cache[a + 50][b + 50][c + 50] != 0){
        return cache[a + 50][b + 50][c + 50];
    }
    else if(a <= 0 || b <= 0 || c <= 0){
        cache[a + 50][b + 50][c + 50] = 1;
    }
    else if(a > 20 || b > 20 || c > 20){
        cache[a + 50][b + 50][c + 50] = w(20, 20, 20);
    }
    else if(a < b && b < c){
        cache[a + 50][b + 50][c + 50] = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
    }
    else{
        cache[a + 50][b + 50][c + 50] = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
    }
    return cache[a + 50][b + 50][c + 50];
}
int main() {
    int a, b, c, res;
    while(1){
        scanf("%d %d %d", &a, &b, &c);
        if(a == -1 && b == -1 && c == -1) break;
        res = w(a, b, c);
        printf("w(%d, %d, %d) = %d\n", a, b, c, res);
    }
    return 0;
}
