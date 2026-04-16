#include <stdio.h>
#include <time.h>
int main(){
    time_t t;
    time(&t);
    struct tm *date;
    date = gmtime(&t);
    printf("%d\n%02d\n%02d\n" , date->tm_year + 1900 , date->tm_mon + 1 , date->tm_mday);
    return 0;
}
