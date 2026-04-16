#include <stdio.h>
#define MAX_SIZE 128
int isall(int arr[][MAX_SIZE], int size, int x, int y);
void div(int arr[][MAX_SIZE], int size, int x, int y, int *white, int *blue);
int main(){
    int arr[MAX_SIZE][MAX_SIZE] = {0, };
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            scanf("%d", &arr[i][j]);
    int white = 0, blue = 0;
    div(arr, n, 0, 0, &white, &blue);
    printf("%d\n%d", white, blue);
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
void div(int arr[][MAX_SIZE], int size, int x, int y, int *white, int *blue){
    if(isall(arr, size, x, y)){
        if(!arr[y][x]) (*white)++;
        else (*blue)++;
        return;
    }
    div(arr, size / 2, x, y, white, blue);
    div(arr, size / 2, x + size / 2, y, white, blue);
    div(arr, size / 2, x, y + size / 2, white, blue);
    div(arr, size / 2, x + size / 2, y + size / 2, white, blue);
    return;
}
