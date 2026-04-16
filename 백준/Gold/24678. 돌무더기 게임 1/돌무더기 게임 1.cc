#include <iostream>
using namespace std;
int main(){
    int t; cin >> t;
    while(t--){
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        int cnt = (a % 2) + (b % 2) + (c % 2);
        printf((cnt >= 2) ? "B\n" : "R\n");
    }
    return 0;
}