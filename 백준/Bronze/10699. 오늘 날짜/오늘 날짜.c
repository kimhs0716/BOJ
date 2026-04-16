#include <stdio.h>
#include <time.h>
int main(){
    time_t tnow;
    struct tm *t;
    time(&tnow);
    t = (struct tm*) localtime(&tnow);
    printf("%d-%02d-%02d", 1900 + t->tm_year, t->tm_mon + 1, t->tm_mday);
    return 0;
}