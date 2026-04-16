#include <stdio.h>
int main(){
    int a, score[1000] = {0, }, b, sum, s, count;
    double avg;
    scanf("%d", &a);
    for(int i = 0; i < a; i++){
        sum = 0;
        count = 0;
        scanf("%d", &b);
        for(int j = 0; j < b; j++){
            scanf("%d", &s);
            sum += s;
            score[j] = s;
        }
        avg = (double)sum / b;
        for(int j = 0; j < b; j++){
            if(score[j] > avg) count++;
        }
        printf("%.3f%%\n", (double)count / b * 100);
    }
    return 0;
}
