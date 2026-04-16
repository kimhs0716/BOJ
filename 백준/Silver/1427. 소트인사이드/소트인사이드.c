#include <stdio.h>
#include <string.h>
void countingSort(char *arr, int size){
    int count[10] = {0, };
    int sorted[size];
    for(int i = 0; i < size; i++)
        count[arr[i] - '0']++;
    int k = '0', ind = 0;
    while(k <= '9' && ind < size){
        for(int i = 0; i < count[k - '0']; i++)
            sorted[ind++] = k;
        k++;
    }
    for(int i = 0; i < size; i++)
        arr[i] = sorted[size - i - 1];
}
int main(){
    char arr[11];
    scanf("%s", arr);
    countingSort(arr, strlen(arr));
    for(int i = 0; i < strlen(arr); i++)
        printf("%c", arr[i]);
    return 0;
}
