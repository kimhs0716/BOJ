#include <stdio.h>
#include <string.h>
char* my_strupr(char* str);
int main(){
    char str[1000000];
    int arr[26] = {0, };
    int i = 0;
    int max = 0;
    char m = 0;
    scanf("%s", str);
    my_strupr(str);
    while(str[i] != '\0'){
        arr[str[i] - 'A']++;
        i++;
    }
    for(int i = 0; i < 26; i++){
        max = (max < arr[i]) ? arr[i] : max;
    }
    for(int i = 0; i < 26; i++){
        if(arr[i] == max) {
            if(m == 0) m = i + 'A';
            else {
                printf("?");
                return 0;
            }
        }
    }
    printf("%c", m);
    return 0;
}

char* my_strupr(char* str){
    int i = 0;
    while(str[i] != '\0'){
        if(str[i] >= 'a' && str[i] <= 'z') str[i] += 'A' - 'a';
        i++;
    }
    return str;
}
