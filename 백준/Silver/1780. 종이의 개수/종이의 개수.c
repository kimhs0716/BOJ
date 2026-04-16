#include <stdio.h>
#define MAX_SIZE 2187
int isall(int arr[][MAX_SIZE], int size, int x, int y);
void div(int arr[][MAX_SIZE], int size, int x, int y, int *white, int *blue, int *red);
int main(){
    int arr[MAX_SIZE][MAX_SIZE] = {0, };
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            scanf("%d", &arr[i][j]);
    int white = 0, blue = 0, red = 0;
    div(arr, n, 0, 0, &white, &blue, &red);
    printf("%d\n%d\n%d", red, white, blue);
    return 0;
}
int isall(int arr[][MAX_SIZE], int size, int x, int y){
    if(size == 1){
        return 1;
    }
    int first = arr[y][x];
    for(int i = x; i < x + size; i++)
        for(int j = y; j < y + size; j++)
            if(arr[j][i] != first) return 0;
    return 1;
}
void div(int arr[][MAX_SIZE], int size, int x, int y, int *white, int *blue, int *red){
    if(isall(arr, size, x, y)){
        if(!arr[y][x]) (*white)++;
        else if(arr[y][x] == 1) (*blue)++;
        else (*red)++;
        return;
    }
    div(arr, size / 3, x, y, white, blue, red);
    div(arr, size / 3, x + size / 3, y, white, blue, red);
    div(arr, size / 3, x + 2 * size / 3, y, white, blue, red);
    div(arr, size / 3, x, y + size / 3, white, blue, red);
    div(arr, size / 3, x + size / 3, y + size / 3, white, blue, red);
    div(arr, size / 3, x + 2 * size / 3, y + size / 3, white, blue, red);
    div(arr, size / 3, x, y + 2 * size / 3, white, blue, red);
    div(arr, size / 3, x + size / 3, y + 2 * size / 3, white, blue, red);
    div(arr, size / 3, x + 2 * size / 3, y + 2 * size / 3, white, blue, red);
    return;
}
