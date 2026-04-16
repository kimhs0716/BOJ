#include <stdio.h>
int main(){
    char str[51];
    int alpha[26] = {0, }, max = 0;
    while(scanf("%s", str) != EOF){
        for(int i = 0; str[i]; i++){
            if(str[i] == 32) continue;
            alpha[str[i] - 'a']++;
            if(max < alpha[str[i] - 'a']) max = alpha[str[i] - 'a'];
        }
    }
    for(int i = 0; i < 26; i++){
        if(alpha[i] == max) printf("%c", i + 'a');
    }
    
    return 0;
}