#include <stdio.h>
int main(){
    int num, score, temp;
    char inp[80];
    scanf("%d", &num);
    for(int i = 0; i < num; i++){
        score = 0;
        temp = 0;
        scanf("%s", inp);
        for(int j = 0; inp[j] != NULL; j++){
            if(inp[j] == 'O'){
                temp++;
                score += temp;
            }
            else temp = 0;
        }
        printf("%d\n", score);
    }
    return 0;
}
