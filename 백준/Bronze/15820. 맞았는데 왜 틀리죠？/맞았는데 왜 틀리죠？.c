#include <stdio.h>
int main(){
    int s1, s2;
    int sample = 1, all = 1;
    int a, b;
    scanf("%d %d", &s1, &s2);
    for(int i = 0; i < s1; i++){
        scanf("%d %d", &a, &b);
        if(a != b){
            sample = 0;
        }
    }
    for(int i = 0; i < s2; i++){
        scanf("%d %d", &a, &b);
        if(a != b) {
            all = 0;
        }
    }
    if(sample == 1){
        if(all == 1) printf("Accepted");
        else printf("Why Wrong!!!");
    }
    else printf("Wrong Answer");
    return 0;
}
