#include <iostream>
using namespace std;
int main(){
    char *str[7] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};
    int m, d;
    cin >> m >> d;
    switch(m){
        case 12:
            d += 30;
        case 11:
            d += 31;
        case 10:
            d += 30;
        case 9:
            d += 31;
        case 8:
            d += 31;
        case 7:
            d += 30;
        case 6:
            d += 31;
        case 5:
            d += 30;
        case 4:
            d += 31;
        case 3:
            d += 28;
        case 2:
            d += 31;
    }
    cout << str[d % 7];
    return 0;
}
