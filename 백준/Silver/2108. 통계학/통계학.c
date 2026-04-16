#include <stdio.h>
#include <math.h>
void countingSort(int *arr, int size){
    int count[8001] = {0, };
    int sorted[size];
    for(int i = 0; i < size; i++)
        count[arr[i] + 4000]++;
    int k = -4000, ind = 0;
    while(k <= 4000 && ind < size){
        for(int i = 0; i < count[k + 4000]; i++)
            sorted[ind++] = k;
        k++;
    }
    for(int i = 0; i < size; i++)
        arr[i] = sorted[i];
}
int main(){
    int n, san, jung, choi, min = 4001, max = -4001, range;
    int count[8001] = {0, };
    double sum = 0;
    int max_count = 0;
    scanf("%d", &n);
    int arr[n];
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    countingSort(arr, n);
    for(int i = 0; i < n; i++){
        sum += arr[i];
        min = (min > arr[i]) ? arr[i] : min;
        max = (max < arr[i]) ? arr[i] : max;
        count[arr[i] + 4000]++;
    }
    for(int i = -4000; i <= 4000; i++){
        max_count = (max_count < count[i + 4000]) ? count[i + 4000] : max_count;
    }
    int found = 0;
    for(int i = -4000; i <= 4000; i++){
        if(count[i + 4000] == max_count){
            if(found){
                choi = i;
                break;
            }
            else{
                choi = i;
                found = 1;
            }
        }
    }
    san = floor(sum / n + 0.5);
    jung = arr[n / 2];
    range = max - min;
    printf("%d\n%d\n%d\n%d", san, jung, choi, range);
    return 0;
}
