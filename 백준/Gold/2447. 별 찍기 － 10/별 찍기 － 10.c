#include <stdio.h>

void star(short board[][2500], int n, int x, int y){
    for(int i = x + n / 3; i < n / 3 * 2 + x; i++)
        for(int j = y + n / 3; j < n / 3  * 2 + y; j++)
            board[i][j] = 0;
    if(n == 3) return;
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            star(board, n / 3, n / 3 * i + x, n / 3 * j + y);
}
int main() {
    short board[2500][2500];
    int num;
    scanf("%d", &num);
    for(int i = 0; i < num; i++)
        for(int j = 0; j < num; j++)
            board[i][j] = 1;
	star(board, num, 0, 0);
	for(int i = 0; i < num; i++){
        for(int j = 0; j < num; j++){
            if(board[i][j]) printf("*");
            else printf(" ");
        }
        printf("\n");
	}
	return 0;
}
