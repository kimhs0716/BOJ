#include <stdio.h>
int main(){
    int arr[10000];
    int count = 0, temp;
    for(int i = 1; i <= 10000; i++){
        temp = d(i);
        arr[i] = temp;
        count++;
    }
    for(int i = 1; i <= 10000; i++) if(find(arr, count, i) == 0) printf("%d\n", i);
    return 0;
}

int d(int n){
    int s = n;
    while(n != 0){
        s += n % 10;
        n /= 10;
    }
    return s;
}

int find(int arr[],int count, int o){
    for(int i = 0; i < count; i++) if(arr[i] == o) return 1;
    return 0;
}
