#include <stdio.h>
#include <string.h>
int main(){
    char arr[16];
    scanf("%[^\n]s", arr);
    if(strcmp(arr, "1 2 3 4 5 6 7 8") == 0) printf("ascending");
    else if(strcmp(arr, "8 7 6 5 4 3 2 1") == 0) printf("descending");
    else printf("mixed");
    return 0;
}
