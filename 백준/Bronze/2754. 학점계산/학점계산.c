#include <stdio.h>
int main() {
    char hak[3];
    scanf("%s", hak);
    switch(hak[0]){
        case 'A':
            if(hak[1] == '+') printf("4.3");
            else if(hak[1] == '0') printf("4.0");
            else printf("3.7");
            break;
        case 'B':
            if(hak[1] == '+') printf("3.3");
            else if(hak[1] == '0') printf("3.0");
            else printf("2.7");
            break;
        case 'C':
            if(hak[1] == '+') printf("2.3");
            else if(hak[1] == '0') printf("2.0");
            else printf("1.7");
            break;
        case 'D':
            if(hak[1] == '+') printf("1.3");
            else if(hak[1] == '0') printf("1.0");
            else printf("0.7");
            break;
        case 'F':
            printf("0.0");
            break;
    }
    return 0;
}
