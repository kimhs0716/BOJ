#include <stdio.h>
int check(char board[][50], int x, int y){
    int result = 0;
    char l[2] = {'W', 'B'};
    for(int i = x; i < x + 8; i++){
        for(int j = y; j < y + 8; j++){
            //printf("%d %d %c\n", i, j, board[i][j]);
            if(board[i][j] != l[(i + j) % 2]) result++;
        }
    }
    return (result > 32) ? (64 - result) : result;
}
int main() {
    int n, m, count, min = 64;
    char board[50][50];
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++)
        scanf("%s", board[i]);
    n -= 7;
    m -= 7;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++){
            //printf("%d %d\n", i, j);
            count = check(board, i, j);
            min = (count > min) ? min : count;
        }
    printf("%d", min);
    return 0;
}
