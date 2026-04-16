#include <stdio.h>

int check(char board[][9], int x, int y) {
    int temp[9];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            temp[i * 3 + j] = board[y / 3 * 3 + i][x / 3 * 3 + j];
        }
    }
    for (int i = 0; i < 9; i++) {
        if (board[y][x] == board[i][x] && y != i) return 0;
        if (board[y][x] == board[y][i] && x != i) return 0;
        if (temp[i] == temp[y % 3 * 3 + x % 3] && i != (y % 3 * 3 + x % 3)) return 0;
    }
    return 1;
}

void printBoard(const char board[][9]) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++)
            printf("%d", board[i][j]);
        printf("\n");
    }
}

int dfs(char board[][9], int x, int y) {
    if(x * y == 64 && board[y][x] != 0) return 1;
    while (board[y][x] != 0) {
        if(x * y == 64){
            if(board[8][8]) return 1;
            break;
        }
        x++;
        if(x == 9){
            x = 0;
            y++;
        }
    }
    for (int i = 1; i <= 9; i++) {
        board[y][x] = i;
        if (check(board, x, y) == 0) continue;
        if (x * y == 64) return 1;
        int res = dfs(board, (x == 8) ? 0 : (x + 1), (x == 8) ? (y + 1) : y);
        if (res) return 1;
    }
    board[y][x] = 0;
    return 0;
}

int main() {
    char board[9][9];
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++){
            scanf(" %c", &board[i][j]);
            board[i][j] -= '0';
        }
    dfs(board, 0, 0);
    printBoard(board);
    return 0;
}
